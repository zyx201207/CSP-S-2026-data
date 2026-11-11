#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int temp[N];
void merge_sort(int* a, int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	merge_sort(a, l, mid);
	merge_sort(a, mid + 1, r);
	int i = l, j = mid + 1, p = l;
	while (i <= mid && j <= r) {
		if (a[j] > a[i]) temp[p++] = a[j++];
		else temp[p++] = a[i++];
	}
	while (i <= mid) temp[p++] = a[i++];
	while (j <= r) temp[p++] = a[j++];
	for (p = l; p <= r; ++p) a[p] = temp[p];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[N];
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int ans;
	bool b[N][35] = {0};
	int cnt[35] = {0};
	int tmp, tot = 0;
	for (int i = 1; i <= n; ++i) {
		tmp = a[i];
		tot = 0;
		while (tmp) {
			b[i][tot] = (tmp & 1);
			if (b[i][tot]) ++cnt[tot];
			tmp >>= 1;
			++tot;
		}
	}
	int pow2[35] = {1};
	for (int i = 1; i <= 30; ++i) {
		pow2[i] = (pow2[i - 1] << 1);
	}
	int s[N] = {0}, id = 0;
	for (int i = 29; i >= 0; --i) {
		if (cnt[i] >= m) {
			for (int j = 1; j <= n; ++j) {
				s[++id] = (a[j] & (pow2[i + 1] - 1));
			}
			break;
		}
	}
	merge_sort(s, 1, id);
	ans = INT_MAX;
	for (int i = 1; i <= m; ++i) {
		ans &= s[i];
	}
	cout << ans;
	return 0;
}

