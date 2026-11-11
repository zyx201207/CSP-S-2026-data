#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,dp[N],a[N],ans=0;
void solve(){
	scanf("%lld%lld",&n,&d);
	ans=0;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int z=i+1;z<=j;z++)dp[z]=INT_MAX;
			dp[i]=0;
			for(int z=i;z<=j;z++){
				for(int to=z+1;to<=j;to++){
					if(a[to]-a[z]>d)break;
					dp[to]=min(dp[to],dp[z]+1);
				}
			}
			int cnt=0;
			for(int z=j;z>=i;z--){
				if(a[j]-a[z]>d)break;
				if(dp[j]==dp[z]+1)cnt++;
			}
			if(cnt==2){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int i=1;i<=t;i++){
		solve();
	}
    return 0;
}

