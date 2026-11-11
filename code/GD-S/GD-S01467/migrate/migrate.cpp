#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int a[N],n,d;
int dp[N],cnt[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(n==1){
			printf("0\n");
			continue;
		}
		if(c==11||c==12){
			int _d=a[n]-a[n-1];
			int p=d/_d;
			if(p<=1){
				printf("0\n");
				continue;
			}
			int ans=0;
			for(int i=1;i+(2*p-1)<=n;i++)ans++;
			printf("%lld\n",ans);
		}
		if(c<=10){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					dp[j]=0;cnt[j]=n+1;
				}
				dp[i]=1;cnt[i]=0;
				int l=i,r=i-1,sum=0;
				for(int j=i+1;j<=n;j++){
					while((a[j]-a[l])>d)sum-=dp[l],l++;
					if(l==j)break;
					cnt[j]=cnt[l]+1;
					while(cnt[r+1]+1==cnt[j])r++,sum+=dp[r];
					dp[j]=sum;
				}
				for(int j=i+1;j<=n;j++)if(dp[j]==2)ans++;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
