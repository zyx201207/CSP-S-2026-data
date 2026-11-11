#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct subline{
	int pos;
	int cost;
};

int qread() {
	auto ch = getchar();
	int res = 0;
	while (isdigit(ch)){
		res = (res<<1) + (res<<3) + (ch-'0');
		ch = getchar();
	}
	return res;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c = qread();
	int n = qread(), m = qread();
	int d = qread(), q = qread();
	
	vector<int> sta(m+1);
	for (int i = 1; i <= m; i ++) {
		sta[i] = qread();
	}
	vector<vector<subline> > stline(n+1, vector<subline>());
	for (int i = 1; i <= n; i++) {
		int k = qread();
		stline[i].resize(k+1);
		for (int j = 1; j <= k; j++){
			stline[i][j].pos = qread();
			stline[i][j].cost = qread();
		}
	}
	vector<pair<int, int> > trplan(q);
	for (int i = 1; i <= q; i ++) {
		int from_sta = qread(), to_sta = qread();
		trplan[i] = {from_sta, to_sta};
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

