#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[500005], ar[300005], idx = 0;
int ans[300005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		vector<int> last_display(m + 1, -1);
		idx = 0;
		for (int i2 = i; i2 < n; i2++) {
			if (last_display[a[i2]] != -1) {
				idx = last_display[a[i2]];
			}
			ar[idx] = a[i2];
			last_display[a[i2]] = idx;
			idx++;
		}
		for (int i2 = 0; i2 < idx; i2++) {
			ans[ar[i2]]++;
		}
	}

	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
} 
