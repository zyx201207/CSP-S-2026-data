#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N=505,M=5e5,inf=1e18;
int c,n,m,d,q;
struct node{
	int to,val;
};
int dp[N][N],w[M];
vector<node> stat[M];
#undef int
int main(){
	#define int long long
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dp[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
//	return 1; 
	for(int i=1;i<=n;i++){
		int ki;
		cin >> ki;
//		if(i==338){
//			cout << ki << "\n";
//			return 1;
//		} 
		for(int j=0;j<ki;j++){
			int x,y;
			cin >> x >> y;
			stat[x].push_back({i,y});
//			if(i==339) cout << x << " " << y << " " << j << "\n";
//			if(i==339 && j==500)return 1;
//		if(i==339) return 1;
		}
	} 
	for(int i=1;i<=m;i++){
		for(int j=0;j<stat[i].size();j++){
			for(int k=j+1;k<stat[i].size();k++){
				dp[stat[i][j].to][stat[i][k].to]=min(dp[stat[i][j].to][stat[i][k].to],stat[i][j].val+stat[i][k].val);
				dp[stat[i][k].to][stat[i][j].to]=min(dp[stat[i][k].to][stat[i][j].to],stat[i][j].val+stat[i][k].val);
			}
		} 
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp[i][k]!=inf && dp[k][j]!=inf) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		} 
	} 
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout << dp[i][j] << " ";
//		}
//		cout << "\n";
//	}
	while(q--){
//		if(q==89995) return 1;
		int u,v,ans=inf;
		cin >> u >> v;
		for(int i=0;i<stat[u].size();i++){
			for(int j=0;j<stat[v].size();j++){
				ans=min(ans,stat[u][i].val+stat[v][j].val+dp[stat[u][i].to][stat[v][j].to]);
			}
		}
		cout << ans+w[u]+w[v] << "\n";
	}
	return 0;
}
