#include<bits/stdc++.h>
#define PII pair<long long,long long>
#define x first
#define y second
using namespace std;
const long long M=1e6+10;
const long long N=1e3+10;
long long c,n,m,d,q;
long long w[M],k[N];
vector<PII>e[N];
vector<PII>mp[M];
long long ans[N][N];
void init(){
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++)ans[i][j]=1e18;
	}
}
void dij(long long x){
	priority_queue<PII>pq;
	pq.push({0,x});
	ans[x][x]=0;
	while(!pq.empty()){
		PII t=pq.top();pq.pop();
		if(t.x>ans[x][t.y])continue;
		for(auto i:e[t.y]){
			if(ans[x][i.y]>ans[x][t.y]+i.x){
				ans[x][i.y]=ans[x][t.y]+i.x;
				pq.push({ans[x][t.y]+i.x,i.y});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>w[i];
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			long long x,y;cin>>x>>y;
			mp[x].push_back({i,y});
		}
	}
	for(long long k=1;k<=m;k++){
		if(mp[k].size()<=1)continue;
		for(auto i:mp[k]){
			for(auto j:mp[k]){
				if(i==j)continue;
				e[i.x].push_back({i.y+j.y,j.x});
			}
		}
	}
	init();
	for(long long i=1;i<=n;i++)dij(i);
	while(q--){
		long long u,v;cin>>u>>v;
		long long num=1e18;
		for(auto i:mp[u]){
			for(auto j:mp[v])num=min(num,ans[i.x][j.x]+i.y+j.y);
		}
		cout<<num+w[u]+w[v]<<'\n';
	}
	return 0;
}
