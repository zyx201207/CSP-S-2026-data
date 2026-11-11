#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500005], b[500005], ans[300005], sum[300005];
bool vis[500005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, k = 1, idx = 0, idx_ = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	while(k <= n) {
		while(idx_ <= n) {
			idx++;
			b[idx] = a[idx_];
			idx_++;
			for(int i = 1; i <= idx; i++) {
				if(b[i] == b[idx] && vis[i] == 0) {
					for(int j = i; j < idx; j++) vis[j] = 1;
					break;
				}
			}
		}
		idx_ = 1;
		k++;
		for(int i = 1; i <= idx; i++) {
			if(b[i] && sum[b[i]] < k) {
				ans[b[i]]++;
				sum[b[i]]++;
			}
			b[idx] = 0;
			vis[idx] = 0;
		}
		idx = 0;
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
