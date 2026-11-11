#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, m;
int a[200005];
int b[200005];
int ans[200005];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(ans, 0, sizeof(ans));
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	for(int i=1; i<=m; i++) {
		int t = i;
		for(int j=1; j<=n; j++) {
			if(a[t] == b[j]) {
				for(int k=j+1; k<=n; j++) {
					b[k] = 0;
				}
			}
			else b[j+1] = a[t];
			t++;
		}
			for(int j=1; j<=n; j++) {
			if(b[j]) ans[b[j]]++;
		}
		cout << ans << " ";
	}
}
