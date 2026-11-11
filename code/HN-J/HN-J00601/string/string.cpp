#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n, ans = 0, sum = 0;
	string a = "";
	cin >> n;
	for(long long i = 0; i < n; i++) {
		long long m; char k;
		cin >> m >> k;
		for(long long j = 0; j < m; j++) {
			a += k;
		}
		sum += m;
	}
	if (sum % 2 == 1) {
		long long mid = (sum + 1) / 2 - 1;
		for(long long i = 1; i <= (sum - 1) / 2; i++) {
			if(a[mid + i] != a[mid - i]) {
				ans++;
			}
		}
		cout << ans << "\n";
	} else{
		long long mid1 = sum / 2 - 1, mid2 = mid1 + 1;
		for(long long i = 0; i <= mid1; i++) {
			if(a[mid2 + i] != a[mid1 - i]) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
