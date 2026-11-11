#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back

using namespace std;
typedef long long ll;;
typedef pair<ll,ll> pll;

const int N=1e6+233;
int n,k;
vector<int> t[N];
inline int ppc(int x)
{
    int ans=0;
    while (x) ans+=x&1,x>>=1;
    return ans;
}
int b[N],vis[N];
inline void gogogo(int u)
{
    vis[u]=1;
    for (int i=0;i<t[u].size();i++)
    {
        int v=t[u][i];
        if (!vis[v]&&b[v]) gogogo(v);
    }
}
inline bool chk(int p)
{
    for (int i=1;i<=n;i++) b[i]=p>>i-1&1;
    for (int i=1;i<=n;i++) vis[i]=0;
    int cnt=0;
    for (int i=1;i<=n;i++)
        if (!vis[i]&&b[i]) gogogo(i),cnt++;
    return cnt<=2;
}
ll DIS;
inline void Dis(int u,ll d=0)
{
    vis[u]=1;
    if (b[u]==1) return DIS=min(DIS,d),void();
    for (int i=0;i<t[u].size();i++)
    {
        int v=t[u][i];
        if (!vis[v]) Dis(v,d+1);
    }
}
inline ll sol(int p)
{
    for (int i=1;i<=n;i++) b[i]=p>>i-1&1;
    ll ans=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++) vis[j]=0;
        DIS=n,Dis(i);
        ans=max(ans,DIS);
    }
    return ans;
}
inline void _main()
{
    cin>>n>>k;
    for (int i=1,u,v;i<n;i++)
        cin>>u>>v,t[u].pb(v),t[v].pb(u);
    ll mn=1e18;
    for (int i=0;i<1<<n;i++)
        if (ppc(i)==k&&chk(i)) mn=min(mn,sol(i));
    cout<<mn<<endl;
}


int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int c,t;
    cin>>c>>t;
    while (t--) _main();

    return 0;
}


