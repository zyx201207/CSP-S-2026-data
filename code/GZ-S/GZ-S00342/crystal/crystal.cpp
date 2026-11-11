//GZ-S00342 遵义四中 潘成城
#include <bits/stdc++.h>
#define maxn 5000006
using namespace std;
typedef long long ll;

int n;
ll m,a[maxn],d,p[maxn],dp[maxn];
bool tepan=true;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1; i<=n; ++i) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3; i<=n; ++i) {
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) {
			tepan=false;
			break;
		}
	}
	if(tepan) {
		int d=a[2]-a[1];
		int ans=(sqrt(8*(double)(m/d)+1)-1)/2;
		cout<<ans<<endl;
	} else {
		for(int i=2; i<=n; ++i) {
			d=a[i]-a[i-1];
			p[i-1]=d+p[i-2];
		}
		for(int i=1; i<n; ++i) {
			for(int j=0; j<i; ++j) {
				dp[i]+=(p[i]-p[j]);
			}
			if(dp[i]>m) break;
		}
		int ans=upper_bound(dp+1,dp+n,m)-dp;
		cout<<ans<<endl;
	}
	return 0;
}
