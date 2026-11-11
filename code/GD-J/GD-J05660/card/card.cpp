#include <bits/stdc++.h>
using namespace std;
int n, m, tp;
int c[5007], ans[3007], tmp[5007];
bool flag[3007];
void da(int x) {
	int fst = 0;
	for(int i = 1; i <= tp; i++) {
		if(tmp[i] == x){
			fst = i;
			break;
		}
	}
	if(fst == 0) {
		tmp[++tp] = x;
		return;
	}
	for(int i = fst + 1; i <= tp; i++) tmp[i] = 0;
	tp = fst;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) {
		tp = 0, memset(tmp, 0, sizeof(tmp)), memset(flag, 0, sizeof(flag));
		for(int j = i; j <= n; j++) {
			da(c[j]);
		}
		for(int j = 1; j <= tp; j++) flag[tmp[j]] = 1;
		for(int j = 1; j <= m; j++) {
			if(flag[j]) ans[j]++;
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
