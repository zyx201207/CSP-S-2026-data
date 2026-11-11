#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2000010,INF=1e18;
ll c,n,m,a[N],w[N],dp[N],dpp[N],l[N],s,t,st[N][23],Log[N];
void a_1_10(){
	for(int i=1;i<=n;i++){
		w[i]=0;
		l[0]=i;
		dp[i]=1;
		dpp[i]=1;
		dpp[i-1]=0;
		for(int j=i+1,u=i;j<=n;j++){
			while(a[u]+m<a[j])u++;
			if(u==j)break;
			w[j]=w[u]+1;
			l[w[j]]=j;
			dp[j]=dpp[l[w[j]-1]]-dpp[u-1];
			if(dp[j]==2)s++;
			dpp[j]=dpp[j-1]+dp[j];
		}
	}
}
int main(){
	Log[0]=-1;
	for(int i=1;i<=n;i++)Log[i]=Log[i>>1]+1;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){s=0;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(c<=10||n<=1000)a_1_10();
		else s=0;
		printf("%lld\n",s);
	}
} 
