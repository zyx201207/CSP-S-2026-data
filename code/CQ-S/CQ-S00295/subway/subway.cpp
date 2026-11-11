#include<bits/stdc++.h>
using namespace std;
int c,n,m,DD,q;
const int M=5e5+10;
const int N=5e2+10;
struct Edge{
	int L,R;
	long long Len;
	int Next;
}e[(N+M)*2];
bool operator<(Edge x,Edge y){
	return x.Len>y.Len;
}
priority_queue<Edge>pq;
int elast[N+M];
int tot;
long long w[M];
void add(int u,int v,long long D){
	e[++tot]={u,v,D,elast[u]};
	elast[u]=tot;
}
int fath[N+M];
int get_father(int i){
	return i==fath[i]?i:fath[i]=get_father(fath[i]);
}
void follow(int i,int j){
	i=get_father(i);
	j=get_father(j);
	if(i!=j) fath[i]=j;
}
long long dis[N+M][25];
int f[N+M][25];
int d[N+M];
void dfs(int x,int fa){
	f[x][0]=fa;
	d[x]=d[fa]+1; 
	for(int i=1;i<=20;i++){
		f[x][i]=f[f[x][i-1]][i-1];
		if(!f[x][i]) break;
		dis[x][i]=dis[x][i-1]+dis[f[x][i-1]][i-1];
	} 
	for(int i=elast[x];i;i=e[i].Next){
		if(e[i].R==fa) continue;
		dis[e[i].R][0]=e[i].Len;
		dfs(e[i].R,x);
	}
}
long long LCA(int u,int v){
	if(d[u]<d[v]) swap(u,v);
	long long ret=0;
	for(int i=20;i>=0;i--){
		if(d[f[u][i]]>=d[v]){
			ret+=dis[u][i];
			u=f[u][i];
		}
	}
	if(u==v) return ret;
	for(int i=20;i>=0;i--){
		if(f[u][i]!=f[v][i]){
			ret+=dis[u][i];
			ret+=dis[v][i];
			u=f[u][i];
			v=f[v][i];
		}
	}
	ret+=dis[u][0];
	ret+=dis[v][0];
	u=f[u][0];
	v=f[v][0];
	return ret;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>DD>>q;
	for(int i=1;i<=n+m;i++) fath[i]=i;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			long long t;
			cin>>a>>t;
			pq.push({i+m,a,t,0});
		}
	}
	while(!pq.empty()){
		int u=pq.top().L;
		int v=pq.top().R;
		long long t=pq.top().Len;
		pq.pop();
		if(get_father(u)==get_father(v)) continue;
		follow(u,v);
		add(u,v,t);
		add(v,u,t);
	}
	dfs(1,0);
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y) cout<<"0\n";
		else cout<<LCA(x,y)+w[x]+w[y]<<'\n';
	}
	return 0;
}

