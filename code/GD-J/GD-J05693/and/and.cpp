#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#define ll long long

using namespace std;
const int MAXN = 2e5 + 10;
int n, m;
int a[MAXN];
int maxx = 0;
int ans = 0;
int tong[4];
bool pan = 1;
bool pan_4 = 1;
bool check(int x) {
	while(x) {
		if(x % 2 == 0) return 0;
		x /= 2;
	}
	return 1;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
		if(a[i] < 4) tong[a[i]] ++;
		else pan_4 = 0;
		pan &= check(a[i]);
		maxx = max(maxx, a[i]);
	}
	if(m == 1) {//O(1)
		cout << maxx;
	}
	else if(pan_4) {//O(1)
		if(tong[3] >= m) cout << 3;
		else if(tong[2] + tong[3] >= m) cout << 2;
		else if(tong[1] + tong[3] >= m) cout << 1;
		else cout << 0;
	}
	else if(m == n) {//O(n)
		ans = a[1];
		for(int i = 2;i <= n;i ++) {
			ans &= a[i];
		}
		cout << ans;
	}
	else if(pan) {//O(n log n)
		sort(a + 1, a + 1 + n);
		cout << a[n + 1 - m]; 
	}
	else if(m == 2) {//O(n^2)
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j <= n;j ++) {
				if(i == j) continue;
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
	}
	else {
		sort(a + 1, a + 1 + n);
		cout << a[n + 1 - m];
	}
	return 0;
}

