#include <bits/stdc++.h>
using namespace std;
long long m,a[500005],dp[500005];
int n,d;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(n<=10000) {
		for(d=2;d<=n;d++) {
			long long minn=1145141919810123456;
			for(int i=1;i<=n-d+1;i++) {
				int j=i+d-1;
				dp[i]=dp[i+1]+a[j]-a[i];
				if(dp[i]<minn) minn=dp[i];
			}
			if(minn>m) break;
		}
		cout << d-1;	
	}
	else {
		long long u=a[2]-a[1];	
		for(int d=2;d<=n;d++) {
			u+=d*(a[2]-a[1]);
			if(u>n) break;
		}
		cout << d-1;
	}
	return 0;
}