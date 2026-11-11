#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;//Oct31==Dec25?
const int N=2e6+5;
int c,T,n;
ll d,a[N],dp[N],ans=0;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--) {
		ans=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++) cin>>a[i];
		if(a[n]-a[1]<=d) {
			cout<<0<<'\n';
			continue;
		}
		for(int r=1; r<=n; r++) {
			memset(dp,0x3f,sizeof dp);
			dp[r]=0;
			for(int i=r+1; i<=n; i++) {
				for(int j=r; j<i; j++) {
					if(abs(a[i]-a[j])>d) continue;
					dp[i]=min(dp[i],dp[j]+1);
				}
				ll cnt=0;
				for(int j=1; j<i; j++) {
					if(abs(a[i]-a[j])<=d&&dp[i]==dp[j]+1) cnt++;
				}
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

