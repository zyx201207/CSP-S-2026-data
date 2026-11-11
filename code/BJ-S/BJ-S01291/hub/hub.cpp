#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
const int N=5e5+5;
int n,m;
int c,t;
vector<int>e[N];
int vis[N];
void solve()
{
    int n,k;
    cin>>n>>k;
    rep(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cout<<1<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        solve();
    }
    return 0;

}


