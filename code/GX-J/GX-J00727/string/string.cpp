#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
int n = 0;
std::string s = "";
std::string s1 = "",s2 = "";
bool Is(std::string s1, std::string s2)
{
    std::reverse(s2.begin(),s2.end());
    return s1 == s2;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        std::cin>>x;
        char c = ' ';
        std::cin>>c;
        for(int j=0;j<x;j++)
        {
            s+=c;
        }
    }
    n = (int)(s.size());
    for(int i=0;i<n/2;i++)
    {
        s1+=s[i];
    }
    for(int i=n-1;i>n/2;i--)
    {
        s2+=s[i];
    }
    if(s2 != s1)
    {
        int ans = 0;
        for(int i=0;i<n/2;i++)
        {
            if(s1[i] != s2 [i]) ans++;
        }
        std::cout<<ans<<std::endl;
    }else{
    std::cout<<0<<std::endl;}
    return 0;
}
