#include<bits/stdc++.h>
using namespace std;
long long a[1000001],b[1000001],sa[1000001];
long long n,m;
bool check(long long x)
{
    for(int i = 1;i<=n-x+1;i++)
    {
        if(a[i+x-1]*x-(sa[i+x-1]-sa[i-1])<=m)return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++)sa[i] = sa[i-1] + a[i];
    long long ans = 0;
    long long l = 1,r = n;
    while(l<=r)
    {
        long long mid = (l + r) / 2;
        if(check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout<<ans<<endl;
    return 0;
}
