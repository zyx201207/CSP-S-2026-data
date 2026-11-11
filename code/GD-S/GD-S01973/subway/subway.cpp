#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1;
int c,n,m,d,q,w[N],kl;
int sd[501][501]={};
int t;
struct edge{
	int k,t;
};
struct kksk{
	int to,w;
	bool operator<(const kksk&ot)const{
		return w<ot.w;
	}
};
int inf=0x3f3f3f;
vector <edge> dx[N];
vector <edge> mp[501];
priority_queue <kksk> qp;
int dis[501];
void dj(int x,int y){
	for(int i=1;i<=n;i++) dis[i]=inf;
	dis[x]=0;
	if(x==y) return;
	qp.push({x,0});
	while(!qp.empty()){
		kksk tp=qp.top();
		qp.pop();
		int u=tp.to;
		for(auto v:mp[u]){
			if(dis[u]+v.k<dis[v.t]){
				dis[v.t]=dis[u]+v.k;
				qp.push({dis[v.t],v.k});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int ki,ti;
		cin>>kl;
		for(int j=1;j<=kl;j++){
			cin>>ki>>ti;
			dx[ki].push_back({i,ti});
		}
	}
	memset(sd,inf,sizeof(sd));
	for(int i=1;i<=m;i++){
		for(auto x:dx[i]){
			for(auto y:dx[i]){
				if(x.k==y.k) continue;
				sd[x.k][y.k]=min(sd[x.k][y.k],x.t+y.t);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(sd[i][j]==inf) continue;
			mp[i].push_back({sd[i][j],j});
		}
	}
	int x,y,ans=inf;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(auto xv:dx[x]){
			for(auto yv:dx[y]){
				dj(xv.k,yv.k);
				ans=min(ans,dis[yv.k]+xv.t+yv.t+w[x]+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
