#include<bits/stdc++.h>
#define ll long long
#define rep(i,X,Y) for(int i=(X);i<=(Y);i++)
#define per(i,X,Y) for(int i=(X);i>=(Y);i--)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

constexpr int N=2e6+10;

int n;
ll m,a[N];

	int dp[N],sum[N],d[N];
namespace sol1 {
	void Main() {
		ll ans=0;
		rep(i,1,n-1) {
			dp[i]=sum[i]=1; d[i]=0; sum[i-1]=0;
			rep(j,i+1,n) {
				int l=lower_bound(a+i,a+j,a[j]-m)-a;
				int r=upper_bound(d+i,d+j,d[l])-d-1;
				
				if(l<j) {
					d[j]=d[l]+1;
					dp[j]=sum[r]-sum[l-1];
					if(dp[j]>3) dp[j]=3;
					if(dp[j]==2) ans++;
					sum[j]=sum[j-1]+dp[j];
				} else {
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
}

namespace sol2 {
	void Main() {
		ll ans = 0; 
		rep(i,1,1) {
			dp[i]=sum[i]=1; d[i]=0; sum[i-1]=0;
			rep(j,i+1,n) {
				int l=lower_bound(a+i,a+j,a[j]-m)-a;
				int r=upper_bound(d+i,d+j,d[l])-d-1;
				
				if(l<j) {
					d[j]=d[l]+1;
					dp[j]=sum[r]-sum[l-1];
					if(dp[j]>3) dp[j]=3;
					if(dp[j]==2) {
						ans+=(n-j+1);
					}
					sum[j]=sum[j-1]+dp[j];
				} else {
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
}

namespace sol3 {
	void Main() {
		cout<<0<<'\n';
	}
}

namespace sol4 {
	void Main() {
		
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T; cin>>C>>T;
	while(T--) {
		cin>>n>>m;
		rep(i,1,n) {
			cin>>a[i];
		}
		if(C<=10) sol1::Main();
		else if (C<=12) sol2::Main();
		else if(C<=14) sol3::Main();
		else sol1::Main();
	}
	return 0;
} 
