#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,d;
const int N=5050;
const int inf=1e18;
int a[N],sum[N],cnt[N],dp[N],l[N];
inline int read() {int x;cin>>x;return x;}
void work() {
	n=read();d=read();
	for(int i=1;i<=n;i++) {
		a[i]=read();
	}
	for(int i=1;i<=n;i++) {
		l[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;	
	}
	int ans=0;
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			dp[j]=inf;cnt[j]=0;
		}
		sum[i-1]=0;
		dp[i]=0;cnt[i]=1;
		for(int j=i+1;j<=n;j++) {
			dp[j]=dp[max(l[j],i)]+1;
			int ll=max(l[j],i);
			cnt[j]=cnt[ll];
			if(ll+1<j&&dp[ll+1]==dp[j]-1) cnt[j]=cnt[ll+1]+cnt[j];
			if(ll+2<j&&dp[ll+2]==dp[j]-1) cnt[j]=cnt[ll+2]+cnt[j]; 
			if(cnt[j]==2) {
				ans++;
//				cerr<<i<<" "<<j<<" "<<ll<<endl;
			}
		}
	}
	cout<<ans<<endl;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	c=read();t=read();
	while(t--) work();
	return 0;
}
