#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int N = 5e5 + 5;

int n;
ll m;
ll a[N];
ll diff[N];
ll pre[N];
ll pre1[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = n - 1; i >= 1; i--) {
		diff[i] = a[i + 1] - a[i];
		pre[i] = diff[i] + pre[i + 1];
		pre1[i] = pre[i] + pre1[i + 1];
	}
	int left = n, right = n;
	int len = 1;
	while (left >= 1) {
		if (pre1[left] - pre1[right] - (right - left) * pre[right] <= m) {
			len = max(len, right - left + 1);
			left--;
		} else {
			right--;
		}
	}
	cout << len;
	return 0;
} 
