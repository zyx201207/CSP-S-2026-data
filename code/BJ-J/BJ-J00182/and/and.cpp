#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdlib>

#define int32_t int64_t

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int32_t num, choose;
    std::cin>>num>>choose;
    std::vector<int32_t> nums(num+1);
    for(int32_t i = 1;i<=num;i++)
    {
        std::cin>>nums[i];
    }
    std::vector<bool> visited(num+1,true);
    int32_t result = 0;
    for(int32_t i = 32;i>=0;i--)
    {
        int32_t cnt = 0;
        for(int32_t j = 1;j<=num;j++)
        {
            int32_t n = nums[j]&(1LL<<i);
            if(visited[j]&&n)
            {
                cnt++;
            }
        }
        if(cnt>=choose)
        {
            result|=(1LL<<i);
            for(int32_t j = 1;j<=num;j++)
            {
                int32_t n = nums[j]&(1LL<<i);
                if(!n)
                {
                    visited[j] = false;
                }
            }
        }
    }
    std::cout<<result;
    return EXIT_SUCCESS;
}
