#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500001], cnt[300001];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
	} 
	for(int i = 1;i <= n;++i) {
		int h = i;
		while(h <= n + 1) {
			bool f = 0;
			for(int k = n;k > h;--k) {
				if(a[k] == a[h]) {
					h = k;
					cnt[a[h]]++;;
					f = 1;
					h++;
					break;
				}
			}
			if(!f) {
				cnt[a[h]]++;
				h++;
			}
		}
	}
	for(int i = 1;i <= m;++i) {
		cout << cnt[i] << " ";
	}
	return 0;
}
