#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e18;
int c,n,m,d,q,w[500005];
vector<pair<int,int>> a[500005];//n
int dp[505][505];//dp[i][j]线路i转线路j的最小时间 
void makedp(){//Floyd
	for(int i=1;i<=n;i++){//O(500^2)
		for(int j=1;j<=n;j++){
			dp[i][j]=INF;
		}
		dp[i][i]=0;
	}
	//对于能直接通过站厅连接的线路
	for(int i=1;i<=m;i++){//O((5*10^5)*(20^2))
		for(pair<int,int> x:a[i]){
			for(pair<int,int> y:a[i]){
				if(x==y) continue;
				dp[x.first][y.first]=min(dp[x.first][y.first],x.second+y.second);
				dp[y.first][x.first]=min(dp[y.first][x.first],x.second+y.second);
				//cout<<x.second+y.second<<'\n';
			}
		}
	}
	//Floyd
	for(int i=1;i<=n;i++){//O(500^3)
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==j||i==k||k==j) continue;
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){//m<=500005
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){//n<=500
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			//站厅x走到线路i需要y分钟
			a[x].push_back({i,y});//a[x].size()<=20
		}
	}
	makedp();
	while(q--){//O((10^5)*(20^2))
		int s,t;
		cin>>s>>t;
		int ans=INF;
		for(pair<int,int> x:a[s]){
			for(pair<int,int> y:a[t]){
				ans=min(ans,x.second+y.second+dp[x.first][y.first]);
			}
		}
		cout<<ans+w[s]+w[t]<<'\n';
	}
	return 0;
}
