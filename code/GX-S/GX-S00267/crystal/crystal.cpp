#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
long long n,m;
long long maxa = -1e13,mina = 1e13;
std::vector<long long > a;
long long f(int p, std::vector<long long> arr)
{
    int i = 0;
    int mm = m;
    while(arr[++i]<=p);
    i--;
    int ans = 0;
    int continueNUM = 0;
    for(;i>=0 and arr[i]<=p;i--)
    {
        ans++;
        mm-=(abs(p-arr[i]));
        if(mm<=0)
        {
            if(mm<0) i++;
            break;
        }
    }
    return ans;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        long long x;
        std::cin>>x;
        a.push_back(x);
        maxa = std::max(a[i],maxa);
        mina = std::min(a[i],mina);
    }
    std::sort(a.begin(),a.end());
    long long ans = -1e9;
    for(int i = mina;i<=maxa;i++)
    {
        ans = std::max(ans,f(i,a));
    }
    std::cout<<ans<<std::endl;
}
