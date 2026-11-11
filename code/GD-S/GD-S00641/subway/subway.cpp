#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+510,M=2e6+1010,logN=21;//N->dot M->side
typedef pair<int,int> pii; 
int c,n,m,d,q,h[M<<1],idx=1,lg[N],Ti;
int p[N],s,t,dis[N],dep[N],fa[N][logN];
int sum,pos,ti;
struct edge{
	int v,w,ne;
}e[M<<1];
vector<int> ed[N];
void add(int from,int to,int w){
	e[++idx]={to,w,h[from]};
	h[from]=idx;
}
void dijk(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<pii> q;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;q.pop();
		for(int i=h[u];i;i=e[i].ne){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}
void init(){
	lg[1]=0;
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
}
void dfs(int u,int father){
	dep[u]=dep[father]+1;
	fa[u][0]=father;
	for (int i=1;i<=lg[n];i++)
	fa[u][i]=fa[fa[u][i-1]][i-1];
	for (auto v:ed[u]){
		if (v==father) continue;
		if (!dep[v]){
			dep[v]=dep[u]+1;
			dfs(v,u);
		}
	}
}
int LCA(int u,int v){
	if (dep[u]<=dep[v]) swap(u,v);
	if (u==v) return u;
	for (int i=lg[n];i>=0;i--)
	if (dep[fa[u][i]]>=dep[v])
	u=fa[u][i];
	if(u==v) return u;
	for (int i=lg[n];i>=0;i--)
	if (fa[u][i]!=fa[v][i])
	u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++){
		scanf("%lld",&p[i]);
		add(n+i,n+m+i,p[i]);
		add(n+m+i,n+i,p[i]);
		ed[m+n+i].push_back(n+i);
		ed[n+i].push_back(n+i+m);
	}
	for (int i=1;i<=n;i++){
		scanf("%lld",&sum);
		for (int j=1;j<=sum;j++){
			scanf("%lld%lld",&pos,&ti);
			Ti=ti;
			add(m+n+pos,i,ti);
			add(i,m+n+pos,ti);
			ed[m+n+pos].push_back(i);
			ed[i].push_back(m+n+pos);
		}
	}
	if (12<=c&&c<=19){
		init();
		for (int i=1;i<=2*m+n;i++){
			ed[i].push_back(0);
			ed[0].push_back(i);
		}
		dfs(0,1e6+505);
		while (q--){
			scanf("%lld%lld",&s,&t);
			s+=n,t+=n;
			int lca=LCA(s,t);
			printf("%lld\n",Ti*(dep[s]+dep[t]-2*dep[lca]));
		}
	}
	else{
		while (q--){
			scanf("%lld%lld",&s,&t);
			dijk(n+s);
			printf("%lld\n",dis[n+t]);
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

