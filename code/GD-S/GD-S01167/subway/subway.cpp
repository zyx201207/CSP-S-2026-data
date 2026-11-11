#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int sn=5e5+1,N=sn+500,Q=1e5+1;
int c,n,m,d,q,w[sn];
ll dis[N],ans[Q];
vector<pair<int,int>>g[N];
struct que{int x,y,id;}ql[Q];
void dij(int s){
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
	memset(dis,0x3f,sizeof dis),q.push({dis[s]=0,s});
	while(q.size()){
		auto[D,x]=q.top();q.pop();
		if(D!=dis[x])continue;
		for(auto[y,z]:g[x])if(dis[y]>D+z)q.push({dis[y]=D+z,y});
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1,k,j,a,t;i<=m;i++)
		for(cin>>k,j=1;j<=k;j++)cin>>a>>t,g[a].push_back({n+i,t}),g[n+i].push_back({a,t});
	for(int i=1,x,y;i<=q;i++)cin>>y>>x,ql[i]={x,y,i};
	sort(ql+1,ql+q+1,[](que x,que y){return x.x<y.x;});
	for(int i=1;i<=q;i++){
		auto[x,y,id]=ql[i];
		if(x!=ql[i-1].x)dij(x);
		ans[id]=dis[y]+w[x]+w[y];
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	return 0; 
}
