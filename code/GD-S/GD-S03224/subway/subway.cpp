#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
#define int long long
int b[M],a[M],tim[M];
int h[M+N],ne[M*10],e[M*10],w[M*10],idx;
void add(int x,int y,int z){
	e[++idx]=y,ne[idx]=h[x],w[idx]=z,h[x]=idx;
}
int C,n,m,d,q;
struct node{
	int id,dis;
	bool operator >(const node &x) const{
		return dis>x.dis;
	}
};
int dis[N+M];
bool vis[N+M];
void dij(int st){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<node,vector<node>,greater<node> > q;
	q.push({st,0}); dis[st]=0;
	while(!q.empty()){
		node t=q.top(); q.pop();
		if(vis[t.id]) continue;
		vis[t.id]=1;
		for(int j=h[t.id];j;j=ne[j]){
			int i=e[j];
			if(dis[i]>t.dis+w[j]){
				dis[i]=t.dis+w[j];
				q.push({i,dis[i]});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){	
			cin>>a[j]>>tim[j];
			add(m+i,a[j],tim[j]);
			add(a[j],m+i,tim[j]);
		}
	}
	while(q--){
		int st,ed; cin>>st>>ed;
		dij(st);
		cout<<dis[ed]+b[st]+b[ed]<<'\n';
	}
	return 0;
}


