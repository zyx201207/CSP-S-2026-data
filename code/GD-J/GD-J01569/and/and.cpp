#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, TR = 2e6;
int a[N], n, m;
int ch[TR][2], tot = 1, siz[TR], ad[TR], dis[TR], pow2[32];
void dfs(int u){
	for (int i=0; i<=1; i++){
		if (ch[u][i] == 0) continue;
		dis[ch[u][i]] = dis[u] + 1;
		ad[ch[u][i]] = ad[u] + pow2[dis[ch[u][i]]] * i;
		dfs(ch[u][i]);
	}
//	cout << u << " " << siz[u] << " " << dis[u] << " " << ad[u] << '\n';
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	pow2[0] = 1;
	for (int i=1; i<=31; i++) pow2[i] = pow2[i-1] * 2;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		int u = 1, t = a[i];
		while (t > 0) {
//			cout << u << " " << t << "\n";
			siz[u]++;
			if (ch[u][t & 1] == 0) ch[u][t & 1] = ++tot;
			u = ch[u][t & 1];
			if (t == 1) siz[u]++; 
			t >>= 1;
		}
	}
	dis[1] = -1;
	dfs(1);
	int mxans = 0;
	for (int i=1; i<=tot; i++){
		if (siz[i] >= m) mxans = max(mxans, ad[i]);
	}
	cout << mxans << '\n';
	return 0;
}
