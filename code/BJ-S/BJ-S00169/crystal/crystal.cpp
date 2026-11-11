#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <algorithm>

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int32_t num, num_add;
    std::cin>>num>>num_add;
    std::vector<int32_t> nums(num+1);
    for(int32_t i = 1;i<=num;i++)
    {
        std::cin>>nums[i];
    }
    sort(nums.begin()+1,nums.end());
    std::vector<int32_t> diff(num+1);
    for(int32_t i = 2;i<=num;i++)
    {
        diff[i] = nums[i]-nums[i-1];
    }
    std::vector<int32_t> sum(num +1);
    for(int32_t i = 2;i<=num;i++)
    {
        sum[i] = sum[i-1]+diff[i];
    }
    int32_t result = 1;
    for(int32_t i = 1;i<=num;i++)
    {
        int32_t cnt = 0;
        for(int32_t j = 1;j<=i;j++)
        {
            cnt+=(sum[i]-sum[j]);
        }
        if(cnt<=num_add&&cnt>=0)
        {
            result = i;
        }
    }
    std::cout<<result;
    return EXIT_SUCCESS;
}
