#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=505;
ll W[N],dis[N],f[M][M];
struct edge{
    int v;
    ll w;
};
bool operator <(edge aa,edge bb){
    return aa.w>bb.w;
}
vector<edge> p[N],e[N];
bool vis[N];
void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<edge> q;
    dis[s]=0;
    q.push({s,dis[s]});
    while(!q.empty()){
        int u=q.top().v;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(edge y:e[u]){
            int v=y.v;
            ll w=y.w;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(f,0x3f,sizeof(f));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
        cin>>W[i];
	}
	for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int s;
            ll t;
            cin>>s>>t;
            p[s].push_back({i,t});
        }
	}
	for(int i=1;i<=m;i++){
        for(edge x:p[i]){
            for(edge y:p[i]){
                int u=x.v;
                int v=y.v;
                if(u==v) continue;
                f[u][v]=min(f[u][v],x.w+y.w);
                f[v][u]=min(f[v][u],x.w+y.w);
            }
        }
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j && f[i][j]<0x3f3f3f3f3f3f3f3f){
                e[i].push_back({j,f[i][j]});
            }
        }
	}
	for(int i=1;i<=n;i++){
        dij(i);
        for(int j=1;j<=n;j++){
            f[i][j]=dis[j];
        }
	}
	while(q--){
        int s,t;
        cin>>s>>t;
        ll ans=1e18;
        for(edge x:p[s]){
            for(edge y:p[t]){
                ans=min(ans,f[x.v][y.v]+x.w+y.w+W[s]+W[t]);
            }
        }
        cout<<ans<<'\n';
	}
	return 0;
}
