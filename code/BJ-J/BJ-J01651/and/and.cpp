#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 200005
#define V 35
ll n,m,a[N],t[N][V],cnt[V],qp[V];
void init()
{
    qp[0]=1;
    for(ll i=1;i<=35;i++)qp[i]=qp[i-1]*2;
}
bool cmp(ll xx,ll yy)
{
    return xx>yy;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    init();
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        for(ll j=0;(a[i]>>j)>0;j++)
        {
            t[i][j]=(a[i]>>j)%2;
            if(t[i][j]==1)cnt[j]++;
        }
    }
    ll bg=0;
    for(ll i=33;i>=0;i--)
    {
        if(cnt[i]>=m)
        {
            bg=i;
            break;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=33;j>=bg+1;j--)
        {
            a[i]-=t[i][j]*qp[j];
        }
    }
    sort(a+1,a+n+1,cmp);
    ll ans=a[1];
    for(ll i=2;i<=m;i++)ans&=a[i];
    cout<<ans<<endl;
    return 0;
}
