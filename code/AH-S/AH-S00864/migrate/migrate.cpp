#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 2E6+5;
LL c,t, n,d,x[N],res, cnt, mi= INT_MAX;
void check(int u, int v,int step) {
	if (step >mi) return ;
	if (u== v) {
		if (step < mi)
			mi = step, cnt = 1;
		else cnt ++;
		return ;
	}
	for (int i = u + 1; i <= v; i ++) {
		if (x[i] <= x[u] + d)
			check(i,v,step+1);
	}
}
int main() {
	freopen("migrate.in","r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >>c >>t;
	while (t--) {
		cin >> n >>d;
		for (int i =1; i <= n; i++) cin >> x[i];
		for (int i = 1; i <= n; i ++) {
			for (int j = i + 1; j <=n; j ++) {
				cnt = 0, mi = INT_MAX;
				check(i, j,0);
				if (cnt == 2) res ++;
			}
		}
		cout << res<< '\n', res= 0;
	}
	return 0;
}
