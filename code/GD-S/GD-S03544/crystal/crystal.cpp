#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e5+5;
long long n,m,a[maxn],s[maxn];
bool check(int k)
{
    for(int l=1;l<=n-k+1;l++)
    {
        int r=l+k-1;
        if(a[r]*(r-l+1)-(s[r]-s[l-1])<=m)return 1;
    }
    return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}