#include<bits/stdc++.h>
using namespace std;
//#define ll long long
#define pii pair<long long ,long long> 
const int N=505,M=5e5+5;
const long long inf=1e18;
int c,n,m,d,T;
int a[M],k[N];
long long dp[N][300005],t[N][N];

vector<pii >g[M+N];
priority_queue<pii,vector<pii>,greater<pii > >q;
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			dp[i][j]=inf;
		for(int j=1;j<=n;j++)
			if(i!=j)t[i][j]=inf;
	}
	
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int v;
			long long t;
			cin>>v>>t;
			g[m+i].push_back({v,t});
			g[v].push_back({m+i,t});
		}
	}
	init();
	for(int i=1;i<=n;i++){
		while(!q.empty())q.pop();
		for(auto it:g[m+i]){
			int v=it.first;
			long long w=it.second;
			dp[i][v]=w;
			q.push({dp[i][v],v});
		}
		vector<int>vis(m+n,0);
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(auto it:g[u]){
				int v=it.first;
				long long w=it.second;
				if(u>m){
					if(!vis[v]&&dp[i][v]>t[i][u-m]+w){
						dp[i][v]=t[i][u-m]+w;
						q.push({dp[i][v],v});
					}
				}
				else{
					if(!vis[v]&&t[i][v-m]>dp[i][u]+w){
						t[i][v-m]=dp[i][u]+w;
						q.push({t[i][v-m],v});
					}
				}
			}	
		}
	}
	for(int i=1;i<=T;i++){
		int x,y;
		long long ans=0,cost=inf;
		cin>>x>>y;
		ans+=a[x]+a[y];
		for(int j=1;j<=n;j++){
			cost=min(cost,dp[j][x]+dp[j][y]);
		}
		cout<<ans+cost<<"\n";
	}
	return 0;
}
