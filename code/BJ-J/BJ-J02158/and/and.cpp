#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200010],maxw;
bool dao[200010];
ll ans[200010];
ll k=0;
void tiao(ll v,ll c)
{
    maxw=-1;
    for(int i=1;i<=n;i++)
    {
        if(!dao[i])
        {
            ll dkg=(v & a[i]);
            v=max(dkg,v);
            if(dkg>v) maxw=i;
        }
    }
    if(maxw!=-1) dao[maxw]=1;
    if(c!=1)
    {
        tiao(v,c-1);
    }
    else{
        k++;
        ans[k]=v;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) tiao(a[i],m-1);
    sort(ans+1,ans+n+1);
    cout<<ans[n];
    return 0;
}
