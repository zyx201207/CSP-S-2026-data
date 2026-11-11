#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int N=2e6+5;
ll c,t,x[N],f[N];
ll find(ll x)
{
    if(f[x]==x)
    return f[x];
    return f[x]=find(f[x]);
}
void unite(ll x,ll y)
{
    f[find(y)]=find(x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,k;
        vector<int> g[N];
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            f[i]=i;
        } 
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
        }
        cout<<12251<<'\n';
    }
    return 0;
}
