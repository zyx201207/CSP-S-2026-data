#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const ll INF=1e18;
int n,m,q,w[N],tot;
int hd[N*4],nt[N*8],to[N*8],vis[N*4];
ll va[N*8],d[N*4];
vector<int>v[N];
struct node{
	int v;ll w;
	bool operator<(const node&o)const{return w>o.w;}
};
priority_queue<node> pq;
void add(int u,int v,ll w){
	nt[++tot]=hd[u];
	hd[u]=tot;
	to[tot]=v;
	va[tot]=w;
}
void dij(int s){
	for(int i=0;i<=tot;i++){
		d[i]=INF;
		vis[i]=0;
	}
	d[s]=0;
	pq.push({s,0});
	while(!pq.empty()){
		int u=pq.top().v;
		pq.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=hd[u];i;i=nt[i]){
			int j=to[i];
			if(d[j]>d[u]+va[i]){
				d[j]=d[u]+va[i];
				pq.push({j,d[j]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin>>c>>n>>m>>c>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	tot=m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		vector<int> a(k),t(k),id(k);
		for(int j=0;j<k;j++){
			cin>>a[j]>>t[j];
			id[j]=++tot;
			v[a[j]].push_back(id[j]);
			add(a[j],id[j],t[j]);
			add(id[j],a[j],t[j]);
		}
		for(int j=0;j<k-1;j++){
			add(id[j],id[j+1],0);
			add(id[j+1],id[j],0);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int S=++tot,T=++tot;
		for(int i:v[x]){
			add(S,i,w[x]);
		}
		for(int i:v[y]){
			add(i,T,w[y]);
		}
		dij(S);
		cout<<d[T]<<endl;
		hd[S]=hd[T]=0;
	}
	return 0;
}
