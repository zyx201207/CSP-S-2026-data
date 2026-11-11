#include <iostream>
#define N 200005
using namespace std;

int n, m, a[N], pt[N], vis[N], ptt[N], cnt;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], pt[i] = a[i];
	cnt = n;
	int ans = 0;
	for(int i = 29; i >= 0; i--) {
		int cntt = 0, tmp = 0;
		for(int j = 1; j <= cnt; j++) vis[j] = 0;
		for(int j = 1; j <= cnt; j++) if((pt[j] >> i) & 1) cntt++;
		if(cntt < m) continue;
		else {
			ans += (1 << i);
			for(int j = 1; j <= cnt; j++) {
				if((pt[j] >> i) & 1) ptt[++tmp] = pt[j];
				pt[j] = 0;
			}
			for(int j = 1; j <= tmp; j++) pt[j] = ptt[j];
			cnt = tmp;
		}
	}
	cout << ans;
}

// Orange/Yellow

// CSP ¼õ J ³ýÒÔ S ºÜÄÑ 
