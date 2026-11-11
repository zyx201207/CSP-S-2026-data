//观山湖中学 李朋钊 GZ-S00201
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
const int M = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
template<typename U, typename V> bool cmin(U &x,const V &y){return y<x?x=y,1:0;}
template<typename U, typename V> bool cmax(U &x,const V &y){return y>x?x=y,1:0;}
int n, k, vis[N], d[N], st[N][20], dep[N];
vector<int> G[N];
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    for(auto v:G[u]){
        if(v==fa) continue;
        d[v]=d[u]+1;
        st[v][0]=u;
        dfs(v,u);
    }
}
int lca(int x,int y){
    if(dep[x]>dep[y]){
        swap(x, y);
    }
    for(int i=20;i>=0;i--){
        if(dep[st[y][i]]>=dep[x]){
            y=st[y][i];
        }
    }
    if(x==y) return x;
    for(int i=20;i>=0;i--){
        if(st[x][i]!=st[y][i]){
            x=st[x][i], y=st[y][i];
            break;
        }
    }
    return st[x][0];
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=1;i<n;i++){
        int u, v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(vis,0,sizeof vis);
    memset(st,0,sizeof st);
    memset(d,0,sizeof d);
    for(int i=1;i<=k;i++) vis[i]=1;
    sort(vis+1,vis+1+n);
    ll ans=inf, res=0;
    dfs(1, 0);
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            st[i][j]=st[st[i][j-1]][j-1];
        }
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j&&vis[i]&&vis[j]){
                int Lca=lca(i,j);
                cmax(res,d[i]+d[j]-2*d[Lca]);
            }
        }
	}
    cmin(ans, res);
    while(next_permutation(vis+1, vis+1+n)){
        res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j&&vis[i]&&vis[j]){
                    int Lca=lca(i,j);
                    cmax(res,d[i]+d[j]-2*d[Lca]);
                }
            }
        }
        cmin(ans, res);
    }
    cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t;cin>>c>>t;
	while(t--){
        solve();
	}
	return 0;
}
