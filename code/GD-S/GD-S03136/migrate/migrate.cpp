#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+86;
const int F=1911;
const int K=INT_MAX;
ll c,n,t,m;
ll a[N],cnt,l[N],ans1;
ll dp[F][F],b[F][F];
void dfs(int u,int v,int step,int val,ll num){
	if(step==v&&val==num){
		cnt++;
		return;
	}
	if(dp[step][v]+val>dp[u][v]) return;
	for(int i=1;i<=n;i++){
		if(step!=i&&b[step][i]&&!l[i]){
			l[i]=1;
			dfs(u,v,i,val+1,num);
			l[i]=0;
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans1=0;
		scanf("%lld%lld",&n,&m);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=m) b[i][j]=b[j][i]=1;
				else break;
			}
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) dp[i][j]=K;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(b[i][j]) dp[i][j]=1;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){
					if(i==j||j==k||i==k)continue;
					dp[j][i]=dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
		memset(l,0,sizeof(l));
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				l[i]=1;
				cnt=0;
				dfs(i,j,i,0,dp[i][j]);
				if(cnt==2){
					ans1++;
				}
			}
		}
		printf("%lld\n",ans1);
	}
	return 0;
}

