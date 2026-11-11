#include<bits/stdc++.h>
using namespace std;
typedef  long long ull;
const int N=2e6+5;
ull dp[N];//到i点的最短长度 
ull c,t,n,d,cnt;
ull a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		cnt=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			dp[i]=i-1;
			scanf("%lld",&a[i]);
		}
		int b[n+2];//长度为i的有几个 
		for(int i=2;i<=n;i++){
			memset(b,0,sizeof b);
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]>d) break;
				b[dp[j]+1]++;
				dp[i]=min(dp[i],dp[j-1]+1);
			}
			for(int j=1;j<=i;j++){
				if(b[j]==0) continue;
				if(b[j]!=2) break; 
				if(b[j]==2){
					//printf("%d %d %d %d\n",i,j,b[j],cnt);
					cnt++;
					break;
				}
			} 
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
