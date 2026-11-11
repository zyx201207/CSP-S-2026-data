#include<bits/stdc++.h>
#define pii pair<long long,long long>
#define f first
#define s second
using namespace std;
long long id,n,m,d,q,k,w[1234567],a[1234][1234],dis[1234][1234],x,y,t,ans;
vector<pii>g[512345],qwq,gg[12345];
void gysb(int sta){
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	pq.push({0,sta});
	while(pq.size()){
		long long x=pq.top().s,w=pq.top().f;
		pq.pop();
		if(w>dis[sta][x])continue;
		for(int nx=1;nx<=n;nx++){
			long long nw=w+a[x][nx];
			if(nw<dis[sta][nx])dis[sta][nx]=nw,pq.push({nw,nx});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>id>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)a[i][j]=1e18,dis[i][j]=1e18;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;	
		for(int j=1;j<=k;j++){
			cin>>x>>t;		
			for(auto p:g[x]){
				long long y=p.f,nt=p.s;
				a[i][y]=a[y][i]=min(a[i][y],t+nt);
			}
			g[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)gysb(i);
	while(q--){
		cin>>x>>y,ans=1e18;
		for(auto i:g[x]){
			for(auto j:g[y]){
				ans=min(ans,w[x]+w[y]+dis[i.f][j.f]+i.s+j.s);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
