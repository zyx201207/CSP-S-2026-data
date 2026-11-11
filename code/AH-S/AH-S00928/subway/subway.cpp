#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<pair<long long,long long>> station[500500];
long long k[505];
long long w[500500];
long long dis[505][505];
long long dp[505][505];
long long c,n,m,d,q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			long long A,T;
			cin>>A>>T;
			station[A].push_back({i,T});
		}
	}
	for(long long i=0;i<=n;i++){
		for(long long j=0;j<=n;j++){
			dis[i][j]=INT_MAX;
			dp[i][j]=INT_MAX;
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=0;j<station[i].size();j++){
			for(long long k=0;k<station[i].size();k++){
				if(dis[station[i][j].first][station[i][k].first]>station[i][j].second+station[i][k].second)dis[station[i][j].first][station[i][k].first]=station[i][j].second+station[i][k].second;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(i==j)dp[i][j]=0;
			else dp[i][j]=dis[i][j];
		}
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			if(dis[i][k]==INT_MAX)continue;
			for(long long j=1;j<=n;j++){
				if(dis[i][k]+dis[k][j]<dp[i][j])dp[i][j]=dis[i][k]+dis[k][j];

			}
		}
	}
	long long ans;
	while(q--){
		ans=INT_MAX;
		long long x,y;
		cin>>x>>y;
		for(long long i=0;i<station[x].size();i++){
			for(long long j=0;j<station[y].size();j++){
				if(w[x]+w[y]+dp[station[x][i].first][station[y][j].first]+station[x][i].second+station[y][j].second<ans)ans=w[x]+w[y]+dp[station[x][i].first][station[y][j].first]+station[x][i].second+station[y][j].second;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
