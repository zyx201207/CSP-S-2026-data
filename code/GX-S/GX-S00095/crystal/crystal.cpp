#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ldp,dp;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    ldp=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=2;i<=n;i++)
    {
        dp=ldp+(a[i]-a[i-1])*(i-1);
        if(dp>m)
        {
            cout<<i-1;
            return 0;
        }
        ldp=dp;
    }
    cout<<n;
    return 0;
}
