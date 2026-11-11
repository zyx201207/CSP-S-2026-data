#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int a[N], sum[N];
int n, ans = 0;
ll m;	
bool cmp (int x, int y) {
	return x < y;
}		
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		sum[i] += sum[i - 1] + a[i]; 
		int l = 1, r = i, mid;
		while (l < r) {
			mid = (r + l) >> 1;
			if (sum[mid] / mid > a[l]) {
				ans = max(ans, sum[mid] / mid - a[l] + mid) - 1;
				r = mid;
			} else {
				l = mid + 1;
			}
		}
	}	
	cout << ans;
	return 0;
}		
