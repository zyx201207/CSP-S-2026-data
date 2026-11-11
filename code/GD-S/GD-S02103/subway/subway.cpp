#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int c,n,m,d,q,w[N],kk,a,b,a2,b2;
long long dp[N][N],ans;
vector<pair<int,int> > v[500005];
int main(){ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++) scanf("%d",&w[i]),dp[i][i]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&kk);
		for(int j=1;j<=kk;j++){
			scanf("%d%d",&a,&b);
			v[a].push_back({i,b});
			a2 = a,b2 = b;
		}
	}
	for(int k=1;k<=m;k++){
		int sz = v[k].size();
		for(int i=0;i<sz-1;i++)
			for(int j=i+1;j<sz;j++)
				dp[v[k][i].first][v[k][j].first] = dp[v[k][j].first][v[k][i].first] = v[k][i].second+v[k][j].second;
	}
	for(int k=1;k<=n;k++)	
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				dp[i][j] = dp[j][i] = min(dp[i][j],dp[i][k]+dp[k][j]);
	while(q--){
		scanf("%d%d",&a,&b);
		ans = 1e18;
		for(auto i:v[a]) 
			for(auto j:v[b]) ans = min(ans,dp[i.first][j.first]+i.second+j.second);
		printf("%lld\n",ans+w[a]+w[b]);
	}
}
