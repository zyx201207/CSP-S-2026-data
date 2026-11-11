//观山湖中学 李朋钊 GZ-S00201
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pil pair<int,ll>
const int N = 5e5 + 10;
const int M = 5e5 + 1000;
const int inf = 0x3f3f3f3f;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
template<typename U, typename V> bool cmin(U &x,const V &y){return y<x?x=y,1:0;}
template<typename U, typename V> bool cmax(U &x,const V &y){return y>x?x=y,1:0;}
int C, n, m, d, q;
int w[N], t[N][560], fa[M], st[M][24], dep[M];
ll c[M];
vector<array<ll,3> > G;
vector<pil> G1[M];
int fd(int x){return x==fa[x]?x:fa[x]=fd(fa[x]);}
void kru(){
	sort(G.begin(),G.end(), [](array<ll,3> x,array<ll,3>y){return x[2]<y[2];});
	int cnt=0;
	for(array<ll,3> tmp:G){
        if(cnt==n+m-1) break;
        int u=tmp[0], v=tmp[1];ll w=tmp[2];
        int fu=fd(u), fv=fd(v);
        if(fu==fv) continue;
        cnt++;
        fa[u]=v;
        G1[u].push_back({v, w});
        G1[v].push_back({u, w});
	}
	return ;
}
void dfs0(int u,int fa){
    dep[u]=dep[fa]+1;
    st[u][0]=fa;
    for(pil tmp:G1[u]){
        int v=tmp.first;
        if(v==fa)continue;
        ll W=tmp.second;
        c[v]=c[u]+W;
        dfs0(v, u);
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
struct node{
    int i;ll w;
    bool operator<(const node &t)const{
        return w>t.w;
    }
};
ll dij(int st,int ed){
    vector<ll> dis(n+m+10, Inf);
    vector<bool> vis(n+m+10, 0);
    priority_queue<node> q;
    dis[st]=0;
    q.push({st,0});
    while(!q.empty()){
        node tmp=q.top();
        q.pop();
        vis[tmp.i]=1;
        for(pil tmp2:G1[tmp.i]){
            int v=tmp2.first;
            ll W=tmp2.second;
            if(!vis[v]&&cmin(dis[v],dis[tmp.i]+W)) q.push({v, dis[v]});
        }
    }
    return dis[ed];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	if(C<=8){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            int k;cin>>k;
            for(int j=1;j<=k;j++){
                ll v;
                cin>>v>>t[v][i];
                G1[v].push_back({i+m, t[v][i]});
                G1[i+m].push_back({v, t[v][i]});
            }
        }
        for(int i=1;i<=q;i++){
            int x, y;cin>>x>>y;
            cout<<dij(x, y)+w[x]+w[y]<<'\n';
        }
        return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n+m;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			ll v;
			cin>>v>>t[v][i];
			G.push_back({i+m, v, t[v][i]});
		}
	}
	kru();
	dfs0(1, 0);
	for(int j=1;j<20;j++){
        for(int i=1;i<=n+m;i++){
            st[i][j]=st[st[i][j-1]][j-1];
        }
	}
	for(int i=1;i<=q;i++){
		int x, y;cin>>x>>y;
		int Lca=lca(x, y);
		cout<<c[x]+c[y]-2*c[Lca]+w[x]+w[y]<<'\n';
	}
	return 0;
}
