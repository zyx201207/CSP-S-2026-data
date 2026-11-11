#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll a[N],cnt[5010][5010],sum[N],d;
int dp[5010][5010],n;
deque<int> q;
void solve(){
	ll x=a[2]-a[1];
	ll cnt=d/x;
	if(cnt<1){
		puts("0");
		return;
	}
	ll ans=0;
	for(int i=1;i<=n-cnt;i++){
		ans+=max(0ll,min(cnt-1,n-(i+cnt)));
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _;
	scanf("%d%d",&_,&_);
	while(_--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n>5000){
			solve();
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)dp[i][j]=0,cnt[i][j]=1;
				else dp[i][j]=0x3f3f3f3f,cnt[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			while(!q.empty())q.pop_back();
			q.push_back(i);
			for(int j=i+1;j<=n;j++){
				while(!q.empty()&&a[q.front()]<a[j]-d)q.pop_front();
				if(!q.empty())dp[i][j]=dp[i][q.front()]+1;
				while(!q.empty()&&dp[i][q.back()]>=dp[i][j])q.pop_back();
				q.push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i-1;j<=n;j++)sum[j]=0;
			sum[i]=1;
			int l=i,r=i;
			for(int j=i+1;j<=n;j++){
				if(dp[i][j]==0x3f3f3f3f)break;
				while(dp[i][l]<dp[i][j]-1||a[j]-a[l]>d)l++;
				while(dp[i][r+1]==dp[i][j]-1)r++;
				if(l<=r)cnt[i][j]=sum[r]-sum[l-1];
				sum[j]=sum[j-1]+cnt[i][j];
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)ans+=cnt[i][j]==2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
