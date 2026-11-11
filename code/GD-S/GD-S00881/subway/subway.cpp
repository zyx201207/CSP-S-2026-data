#include <iostream>
#include <vector>
const long long inf=1e18;
const int maxn=500+32;
const int maxm=5e5+32;
long long w[maxn],k[maxn];
std::vector<int> to[maxn],t[maxn];
std::vector<std::pair<int,long long>> id[maxn];
long long dp[maxn][maxn];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			dp[i][j]=inf;
		}
		dp[i][i]=0;
	}
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int c,n,m,d,q;
	std::cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		std::cin>>w[i]; 
	}
	for(int i=1;i<=n;i++){
		std::cin>>k[i];//铁路i经过站台数量 
		for(int j=1;j<=k[i];j++){
			int A,T;
			std::cin>>A>>T;//站台，时间 
			id[A].push_back({i,T});//站台在火车i线路上+时间 
			to[i].push_back(A);
			t[i].push_back(T);//火车到站台时间
		}
	}
	for(int i=1;i<=n;i++){//火车 
		for(int j=0;j<to[i].size();j++){
			int v=to[i][j];//火车经过站台
			long long t1=t[i][j];//到站台时间 
			for(int p=0;p<id[v].size();p++){//站台所在火车 
				int l=id[v][p].first;//火车2
				long long t2=id[v][p].second;
				dp[l][i]=dp[i][l]=std::min(dp[i][l],t1+t2);
			} 
		}
	}
	
	for(int p=1;p<=n;p++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=std::min(dp[i][p]+dp[p][j],dp[i][j]);
			}
		}
	}
	//std::cout<<dp[1][2]<<'\n'<<'\n';
	for(int r=1;r<=q;r++){
		int xr,yr;
		std::cin>>xr>>yr;
		long long ans=inf;
		for(int i=0;i<id[xr].size();i++){
			for(int j=0;j<id[yr].size();j++){
				//std::cout<<dp[id[xr][i].first][id[yr][j].first]<<'\n'<<'\n';
				ans=std::min(ans,dp[id[xr][i].first][id[yr][j].first]+id[xr][i].second+id[yr][j].second);
			}
		}
		std::cout<<w[xr]+w[yr]+ans<<'\n';
	}
	return 0;
}
