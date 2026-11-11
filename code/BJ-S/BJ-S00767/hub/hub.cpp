#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define dle long double
#define fi first
#define sec second
#define rep(i,a,b) for(int i = (a);i<=(b);i++)
#define per(i,a,b) for(int i = (a);i>=(b);i--)
#define endl '\n'
const int MAXN = 1e6+10;vector<int> g[MAXN];
int c,t,n,k,vis[MAXN],vis2[MAXN],d[MAXN],ans = 1e18;
void dfs2(int x,int fa) {
    for(int nx:g[x]) if(nx!=fa&&vis[nx]) 
        vis2[nx] = 1,dfs2(nx,x);
}
void bfs(int s) {
    queue<int> q;q.push(s);
    rep(i,1,n) d[i] = -1;
    d[s] = 0;while(q.size()) {
        int u = q.front();q.pop();
        for(int v:g[u]) if(d[v]==-1) 
            d[v] = d[u]+1,q.push(v);
    }
}
void dfs(int x,int fl) {
    if(x==k+1) { int cnt = 0;
        rep(i,1,n) vis2[i] = 0;
        rep(i,1,n) if(vis[i]&&!vis2[i])
            cnt++,vis2[i] = 1,dfs2(i,0);
        if(cnt>2) return;int mx = 0;
        rep(i,1,n) { int mn = 1e18;
            bfs(i);rep(j,1,n) if(vis[j]) 
                mn = min(mn,d[j]);
            mx = max(mx,mn);
        }ans = min(ans,mx);
        return;
    }rep(i,fl+1,n) vis[i] = 1,
        dfs(x+1,i),vis[i] = 0;
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;while(t--) {
        cin>>n>>k;rep(i,1,n)
        g[i].clear();rep(i,2,n) {
            int u,v;cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }ans = 1e18;dfs(1,0);cout<<ans<<endl;
    }
    return 0;
} 