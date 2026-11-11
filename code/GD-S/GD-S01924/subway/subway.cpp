#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3fLL;
int dp[502][502];
int w[500005];
vector<int>t[502],a[502];
int k[502];
vector<pair<int,int>>g[500005];
vector<int>h[502];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f,sizeof dp);
	int casfsdfasdfsd,n,m,d,q;
	cin>>casfsdfasdfsd>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push_back({i,j});
		}
	}
//	cout<<'a';
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=0;k<g[i].size();k++){
				if(j!=k){
					dp[g[i][j].first][g[i][k].first]=min(
						dp[g[i][j].first][g[i][k].first],
						t[g[i][j].first][g[i][j].second]+t[g[i][k].first][g[i][k].second]
					);
				}
			}
		}
	}
//	cout<<'b';
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	while(q--){
		int x,y,ans=inf;
		cin>>x>>y;
		for(auto i:g[x]){
			for(auto j:g[y]){
				ans=min(ans,dp[i.first][j.first]+t[i.first][i.second]+t[j.first][j.second]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++)
//			cout<<dp[i][j]<<' ';
//		cout<<endl; 
//	}
	return 0;
}
