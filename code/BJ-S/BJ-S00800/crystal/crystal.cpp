#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
//ll!!!
const ll N=1e5+5,M=5e5+5;
ll a[M],dp[N];
ll n,m;
bool isA=1;
bool isB()
{
    int d=a[1]-a[2];
    for(int i=1;i<n;i++)
        if(a[i]-a[i+1]!=d)return 0;
    return 1;
}
bool isC()
{
    ll id=(n+1)/2;
    ll sum=0;
    for(int i=1;i<=n;i++)
        sum+=abs(a[id]-a[i]);
    return (sum<=m);
}
ll B()
{
    ll bns=1;
    ll id=(n+1)/2,i=1;
    while(m>=0&&id+i<=n)
    {
        if(m>=abs(a[id+i]-a[id])&&id+i<=n)
        {
            bns++;
            m-=abs(a[id+i]-a[id]);
        }
        if(m>=abs(a[id-i]-a[id])&&id-i>0)
        {
            bns++;
            m-=abs(a[id-i]-a[id]);
        }
        else
            break;
        i++;
    }
    return bns;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)
            isA=0;
    }
    sort(a+1,a+n+1);
    if(isA||isB())
    {
        cout<<B();
        return 0;
    }
    if(isC())
    {
        cout<<n;
        return 0;
    }
    ll ans=-0x3f3f3f;
    for(ll i=1;i<=n;i++)//mei ju mubiao shu
    {
        memset(dp,0,sizeof(dp));
        for(ll j=1;j<=n;j++)
        {
            for(ll k=m;k>=abs(a[i]-a[j]);k--)
                dp[k]=max(dp[k-abs(a[i]-a[j])]+1,dp[k]);
        }
        for(ll i=1;i<=m;i++)
            dp[1]=max(dp[1],dp[i]);
        ans=max(dp[1],ans);
    }
    cout<<ans;
    return 0;
}
