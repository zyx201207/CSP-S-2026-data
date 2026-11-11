#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=510,INF=1e18;
ll c,n,m,d,q,z[500010],dp[N][N];
vector<ll>v[500010],w[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&z[i]);
	for(int i=1;i<=n;i++){
		ll a;
		scanf("%lld",&a);
		for(int j=1;j<=a;j++){
			ll b,c;
			scanf("%lld%lld",&b,&c);
			v[b].push_back(i);
			w[b].push_back(c);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=INF;
		}
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=j+1;k<v[i].size();k++){
				dp[v[i][j]][v[i][k]]=min(dp[v[i][j]][v[i][k]],w[i][j]+w[i][k]);
				dp[v[i][k]][v[i][j]]=min(dp[v[i][k]][v[i][j]],w[i][j]+w[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll a,b,s;
		s=INF;
		scanf("%lld%lld",&a,&b);
		for(int j=0;j<v[a].size();j++){
			for(int k=0;k<v[b].size();k++){
				s=min(s,dp[v[a][j]][v[b][k]]+w[a][j]+w[b][k]+z[a]+z[b]);
			}
		}
		if(a==b)s=0;
		printf("%lld\n",s);
	}
} 
