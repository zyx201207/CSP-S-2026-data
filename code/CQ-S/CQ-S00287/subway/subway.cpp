#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[720000];
vector<int>a[510000],t[510000];
map<int,int>vis[570000];
int dp[720][720];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int test,n,m,d,q;
	cin>>test>>m>>n>>d>>q;
//	cout<<"YES"<<" "<<n<<endl;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j)dp[i][j]=1e18;
		}
	}
//	cout<<"YES"<<endl;
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,tp;
			cin>>x>>tp;
			vis[x][i]=tp;
			a[x].push_back(i),t[x].push_back(tp);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++){
			for(int z=0;z<a[i].size();z++){
				int x=a[i][j],y=a[i][z];
				dp[x][y]=min(dp[x][y],t[i][j]+t[i][z]);
			}
		}
	} 
//	cout<<"YES"<<endl;
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	/*
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	*/
	
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e15;
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<a[y].size();j++){
				int xp=a[x][i],yp=a[y][j];
				ans=min(ans,dp[xp][yp]+vis[x][xp]+vis[y][yp]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
/*
FLOYD?
*/
