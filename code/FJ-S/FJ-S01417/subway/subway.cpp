#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5,inf=1e9;
ll c,n,m,d,q,a[N],k,dp[505][505],u,v;
pair<ll,ll> s[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>a[i];
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	if(i!=j) dp[i][j]=inf;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
		cin>>s[j].first>>s[j].second;
		for(int j=1;j<k;j++)
		for(int l=j+1;l<=k;l++){
			dp[s[j].first][s[l].first]=s[j].second+s[l].second;
			dp[s[l].first][s[j].first]=s[j].second+s[l].second;
		}
	}
	for(int l=1;l<=m;l++)
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	dp[i][j]=min(dp[i][j],dp[i][l]+dp[l][j]);
	while(q--){
		cin>>u>>v;
		cout<<a[u]+a[v]+dp[u][v]<<'\n';
	}
	return 0;
}
