#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
using namespace std;

const int N=2e6+10;

int n,T,cas;
int pre[N],nxt[N];
ll x[N],d;
ll dp[5010][5010],cnt[5010][5010],sum[5010][5010];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&cas,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		rep(i,1,n) scanf("%lld",&x[i]);
		rep(i,1,n){
			pre[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
			nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		}
		if(cas<=10){
			ll ans=0;
			rep(l,1,n){
				dp[l][l]=0;cnt[l][l]=1,sum[l][l]=1;
				rep(r,l+1,n){
					if(pre[r]==r) break;
					dp[l][r]=dp[l][max(pre[r],l)]+1;
					int j=upper_bound(dp[l]+pre[r],dp[l]+r+1,dp[l][r]-1)-dp[l]-1;
					cnt[l][r]+=sum[l][j]-sum[l][pre[r]-1];
					sum[l][r]=sum[l][r-1]+cnt[l][r];
					if(cnt[l][r]==2ll) ans++;
				}
			}
			printf("%lld\n",ans);
			rep(l,1,n) rep(r,l,n) dp[l][r]=sum[l][r]=cnt[l][r]=0;
		}
		else if(cas>=13&&cas<=14){
			map <ll,int> cnt;
			cnt.clear();
			int l=0;ll ans=0;
			rep(r,1,n){
				while(l<pre[r]-1){
					l++;
					cnt[nxt[l]]++;
				}
				ans+=cnt[pre[r]+1];
			}
			printf("%lld\n",ans);
		}
	}
	return 0; 
} 
