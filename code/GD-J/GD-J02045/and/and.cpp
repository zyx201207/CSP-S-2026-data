#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int n, m, mxidx, ans;
int a[maxn], vis[maxn];
bitset<40> b[maxn];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout); 
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		int x = a[i], idx = 0;
		while(x) {
			b[i][idx] = x & 1;
			x >>= 1;
			idx ++;
		}
		vis[i] = 1;
		mxidx = max(mxidx, idx);
	}
	
	for(int d = mxidx; d >= 0; d --) {
		int cnt = 0;
		for(int i = 1; i <= n; i ++) {
			if(b[i][d] && vis[i])
				cnt ++;
		}
		if(cnt >= m) {
			ans += (1 << d);
			for(int i = 1; i <= n; i ++) {
				if(!b[i][d] && vis[i])
					vis[i] = 0;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
