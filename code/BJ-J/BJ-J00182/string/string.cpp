#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdlib>

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int32_t num;
    std::cin>>num;
    std::string str = "";
    for(int32_t i = 1;i<=num;i++)
    {
        int32_t n;
        char ch;
        std::cin>>n>>ch;
        for(int32_t j = 0;j<n;j++)
        {
            str+=ch;
        }
    }
    std::cout<<str<<"\n";
    int32_t cnt = 0;
    int32_t len = str.size();
    for(int32_t i = 0;i<len/2;i++)
    {
        if(str[i]!=str[len-i-1])
        {
            cnt++;
        }
    }
    std::cout<<cnt;
    return EXIT_SUCCESS;
}
