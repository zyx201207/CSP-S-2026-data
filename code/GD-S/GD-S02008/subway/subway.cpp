#include <bits/stdc++.h>
#define ll long long
using namespace std;

int c,n,m,d,q,u,v,a0,k[510];
ll t0,ans,w[510000];
ll dis[510][510];
ll dp[510][510];

struct data1{
	int v;
	ll w;
};

vector<data1> f[510000];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
//	clock_t st=clock();
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	
	for (int i=1; i<=m; i++)  cin >> w[i];
	
	for (int i=1; i<=n; i++){
		cin >> k[i];
		
		for (int j=1; j<=k[i]; j++){
			cin >> a0 >> t0;
			
			f[a0].push_back({i,t0});
		}
	}
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n ;j++){
			dis[i][j]=dp[i][j]=1e18;
		}
		dis[i][i]=dp[i][i]=0;
	}
	
	for (int i=1; i<=m; i++){
		for (int j=0; j<f[i].size(); j++){
			for (int j1=j+1; j1<f[i].size(); j1++){
				int uu=f[i][j].v, vv=f[i][j1].v;
				ll ww=f[i][j].w+f[i][j1].w;
				
				dis[uu][vv]=min(dis[uu][vv],ww);
				dis[vv][uu]=dis[uu][vv];
			}
		}
	}
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			dp[i][j]=dis[i][j];
//			cout<<dis[i][j]<<"\n";
		}
	}
	
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=i+1; j<=n; j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				dp[j][i]=dp[i][j];
			}
		}
	}
	
//	cout<<"\n";
//	cout<<dp[1][2]<<" "<<dp[2][3]<<"\n";
//	for (int i=1; i<=n; i++){
//		for (int j=1; j<=n; j++){
//			if(dp[i][j]>=1e17)cout<<i<<" "<<j<<"\n";
//		}
//	}
	
//	for (int i=1 ;i<=m; i++)cout<<f[i].size()<<"\n";
	
//	for (int i=0; i<f[123].size(); i++)cout<<f[123][i].v<<" ";
//	cout<<"\n";
//	for (int i=0; i<f[131].size(); i++)cout<<f[131][i].v<<" ";
//	cout<<"\n"<<dp[14][15];
	
	while(q--){
		ans=1e18;
		
		cin >> u >> v;
		
		for (int i=0; i<f[u].size(); i++){
			for (int j=0; j<f[v].size(); j++){
				int uu=f[u][i].v, vv=f[v][j].v;
				ll ww=f[u][i].w+f[v][j].w;
//				cout<<uu<<" "<<vv<<"\n";
				ans=min(ans,ww+dp[uu][vv]);
			}
		}
		
		cout << ans+w[u]+w[v] << "\n";
	}
	
//	clock_t esd=clock();
//	cout<<"Time"<<1.0*(esd-st)/CLOCKS_PER_SEC;
	
	return 0;
}
