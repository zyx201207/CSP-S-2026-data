#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];
int l[200005];
int r[200005];
char x[200005];
int len;
int pos;
int dex = 1;
int cnt;
int ans;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		len += a[i];
	}
	for(int i = 1; i <= n; i++) {
		cnt++;
		l[cnt] = pos + 1;
		r[cnt] = min(pos+a[i],len/2);
		x[cnt] = c[i];
		pos = min(pos+a[i],len/2);
		if(pos == len / 2) break;
	}
	pos = 0;
	for(int i = n; i >= 1; i--) {
		int ll = pos + 1;
		int rr = min(pos+a[i],len/2);
		if(r[dex] < ll) dex++;
		while(1) {
			if(r[dex] >= rr) {
				if(c[i] != x[dex]) ans += rr - ll + 1;
				break;
			} else {
				if(c[i] != x[dex]) ans += r[dex] - ll + 1;
				dex++;
				ll = l[dex];
			}
		}
		pos = min(pos+a[i],len/2);
		if(pos == len / 2) break;
	}
	cout << ans;
	return 0;
}
