#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

const int N = 5e5 + 5;

int temp[N];
void merge_sort(LL* arr, int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	merge_sort(arr, l, mid);
	merge_sort(arr, mid + 1, r);
	int i = l, j = mid + 1, p = l;
	while (i <= mid && j <= r) {
		if (arr[i] > arr[j]) temp[p++] = arr[j++];
		else temp[p++] = arr[i++];
	}
	while (i <= mid) temp[p++] = arr[i++];
	while (j <= r) temp[p++] = arr[j++];
	for (p = l; p <= r; ++p) arr[p] = temp[p];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	LL a[N];
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	merge_sort(a, 1, n);
	
	int team[N], h = 1, t = 0;
	LL sum = 0LL;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		while (a[i] * (t - h + 1) - sum > m && h <= t)
			sum -= team[h], ++h;
		ans = max(ans, t - h + 2);
		sum += a[i];
		team[++t] = a[i];
	}
	
	cout << ans;
	
	return 0;
}
