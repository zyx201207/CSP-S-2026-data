#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

long long f(vector<long long> x,int u,int n,long long d) {
	int dp[2000005]={},t[2000005]={};
	long long cnt=0;
	for (int i=u;i<n;i++) {
		int j=0;
		while (x[i]+d>=x[i+j]) {
			if (dp[i+j]==0 || dp[i+j]>dp[i]+1) {
				dp[i+j]=dp[i]+1;
			} else if (dp[i+j]==dp[i]+1) {
				if (t[i+j]==0) {
					cnt++;
				}
				if (t[i+j]==1) {
					cnt--;
				}
				t[i+j]++;
			}
			j++;
			if (i+j>=n) {
				break;
			}
		}
	}
	return cnt;
}


int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for (int i=0;i<t;i++) {
		int n;
		long long d;
		cin >> n >> d;
		vector<long long> x;
		x.clear();
		long long xi;
		for (int i=0;i<n;i++) {
			cin >> xi;
			x.push_back(xi);
		}
		long long ans=0;
		for (int i=0;i<n;i++) {
			ans += f(x,i,n,d);
		}
		cout << ans << endl;
	}
	return 0;
}
