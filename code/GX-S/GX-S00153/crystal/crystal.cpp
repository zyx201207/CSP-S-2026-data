#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],pre[N],ans;
bool check(int l,int r)
{
    return a[r]*(r-l)-(pre[r-1]-pre[l-1])<=m;
}
void solve(int k)
{
    int l=k,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(k,mid))
        {
            ans=max(ans,mid-k+1);
            l=mid+1;
        }
        else
            r=mid-1;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)   cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)   pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;++i)
        solve(i);
    cout<<ans;
    return 0;
}
