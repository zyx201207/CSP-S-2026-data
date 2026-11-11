#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010];
long long ans;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++) {
		long long sum = m,cnt = 0;
		for(int j  = n;j  && sum;j--) {
			if(a[j] <= a[i]) {
				if(a[i] - a[j] <= sum) {
					cnt++;
				}
				sum = max(1LL *0 ,sum - (a[i] - a[j]));
			}
		}
		ans = max(ans,cnt);
	}
	cout << ans << endl;
	return 0;
}
