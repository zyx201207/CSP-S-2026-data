#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, x, y, sum = 0;
struct node{
	int no[1000], ti[1000], shu;
}s[1000010];
int zhan[1000010];
void solve1() {
	sum = zhan[x] + zhan[y];
	
}
int main() {
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i ++) {
		cin >> zhan[i];
	}
	for (int i = 1;i <= n;i ++) {
		int x;
		cin >> x;
		s[i].shu = x;
		for (int j = 1;j <= x;j ++) {
			cin >> s[i].no[j] >> s[i].ti[j];
		}
	}
	int cha;
	bool f = 0;
	for (int i = 1;i <= n;i ++) {
		if (i == 1) {
			cha = s[i].shu;
			continue;
		}
		if (cha != s[i].shu) {
			f =1;
		}
	}
	if (f == 0) {
		while (q --) {
			int x, y;
			cin >> x >> y;
			solve1();
		}
	}
	return 0;
}
