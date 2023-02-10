

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j,x;
    *returnSize = 2;
    int *ans;
    int *temp;
    temp = (int *)malloc(sizeof(int)*numsSize);
    
    for(i=0;i<numsSize;i++){
        temp[i] = nums[i];
    }
    
    qsort (nums, numsSize, sizeof(*nums), comp);
    
    i = 0;
    j = numsSize - 1;
    ans = (int*)malloc(2 * sizeof(int));
    
    while(i < j){
        if(nums[i]+nums[j] == target) {
            // printf("%d, %d", i,j);
            break;
        }else if(nums[i]+nums[j] > target){
            j -= 1;
        }else {
            i += 1;
        }
    }
    
    ans[0] = -1;
    ans[1] = -1;
    
    for(x=0;x<numsSize;x++){
        if(nums[i] == temp[x] && ans[0] == -1){
            ans[0] = x;
        }else if(nums[j] == temp[x]){
            ans[1] = x;
        }
    }
    
    return ans;
      
}