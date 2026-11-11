#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500010
ll n,m;
ll a[N];
ll pre[N],ans;
ll calc(int x,ll k)
{
    int l=1,r=x,mid,res=1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(k*(x-mid+1)-(pre[x]-pre[mid-1])<=m) res=mid,r=mid-1;
        else l=mid+1;
    }
    return res;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+a[i];
        ans=max(ans,i-calc(i-1,a[i])+1);
    }
    cout<<ans;
    return 0;
}