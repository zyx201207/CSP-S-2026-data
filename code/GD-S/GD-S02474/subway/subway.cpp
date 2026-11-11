#include<bits/stdc++.h>
using namespace std;
const long long INF=4557430888798830399;
long long c,n,m,o,d,q,x[500+5],y[500+5][500+5];
long long a[500],f[500+5],dp[1000][1000];
bool Curry[500000+5],leborn[5000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q),o=m;
	for(int i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	for(int i=0;i<=500;i++)
		for(int j=0;j<=500;j++)
			f[i]=dp[i][j]=INF;
	for(int t=1;t<=n;t++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x[j]>>y[t][j];
			if(Curry[x[j]]){
				o++;
				dp[x[j]][o]=dp[o][x[j]]=y[t][j]+f[x[j]];
				x[j]=o;
			}
			Curry[x[j]]=1;
			f[x[j]]=y[t][j];
			if(j>=2) dp[x[j-1]][x[j]]=dp[x[j]][x[j-1]]=0;
		}
	}
	for(int k=1;k<=o;k++){
		for(int i=1;i<=o;i++){
			for(int j=1;j<=o;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int n,m;
		cin>>n>>m;
		cout<<dp[n][m]+a[n]+a[m]<<'\n';
	}
	
	return 0;
}
