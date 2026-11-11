#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> ma;

struct qwq{
	int v,w;
	bool operator<(const qwq a) const{
		return w>a.w;
	}
};

int n,m,t;

long long a[500005];
vector<qwq>b[500005],c[505];
//m
//m+m
//m+m+n;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>t>>t;
	for(int i=1;i<=m;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		int x=0;
		cin>>x;
		for(int j=1;j<=x;++j){
			int u=0,w=0;
			cin>>u>>w;
			b[u].push_back((qwq){m+i,w});
			b[m+i].push_back((qwq){u,w});
		}
	}
	long long dp[505][505];
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;++i){
		int len=b[i].size();
		for(int j=0;j<len-1;++j){
			for(int k=j+1;k<len;++k){
				int u=b[i][j].v,v=b[i][k].v;
				int w=b[i][j].w+b[i][k].w;
				dp[u][v]=dp[v][u]=w;
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(t--){
		int u=0,v=0;
		cin>>u>>v;
		int len1=b[u].size(),len2=b[v].size();
		long long ans=INT_MAX;
		for(int j=0;j<len1;++j){
			for(int k=0;k<len2;++k){
				ans=min(ans,b[u][j].w+b[v][k].w+dp[b[u][j].v][b[v][k].v]);
			}
		}
		cout<<a[u]+a[v]+ans<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
