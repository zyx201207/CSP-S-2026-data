#include<bits/stdc++.h>
using namespace std;
long long  T1, T2, ki, aij, tij, xr, yr, c, n, m, d, q, w[500005], ans;

struct zhan {
	long long aik; //经过第几号站 
	long long tik; //下车到站厅用时 
};
vector<zhan> xian[502];

struct Node {
	long long dtx; //通过第几条地铁线
	long long v; //到达第几号站 
};
vector<Node> dtz[500005];

bool B[500005];

void jh(long long x, long long y, long long tot, long long DT) {
	if(x == y) {
		ans = min(ans, tot);
		return;
	}
	for(int i = 0; i < (int)dtz[x].size(); i ++) {
		if(B[dtz[x][i].v] == false) {
			if(DT == dtz[x][i].dtx) {
				B[dtz[x][i].v] = true;
				jh(dtz[x][i].v, y, tot, DT);
				B[dtz[x][i].v] = false;
			} else {
					for(int k = 0; k < (int)xian[dtz[x][i].dtx].size(); k ++) {
						if(xian[dtz[x][i].dtx][k].aik == x) {
							T1 = xian[dtz[x][i].dtx][k].tik;
							break;
						}
					}
				/*for(int k = 0; k < (int)xian[DT].size(); k ++) {
					if(xian[DT][k].aik == x) {
						T1 = xian[DT][k].tik;
						break;
					}
				}*/
				for(int k = 0; k < (int)xian[dtz[x][i].dtx].size(); k ++) {
					if(xian[dtz[x][i].dtx][k].aik == dtz[x][i].v) {
						T2 = xian[dtz[x][i].dtx][k].tik;
						break;
					}
				}
				B[dtz[x][i].v] = true;
				jh(dtz[x][i].v, y, tot + T1 + T2, dtz[x][i].dtx);
				B[dtz[x][i].v] = false;
			}
		}
	}
	return;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i ++) {
		scanf("%lld", &w[i]);
	}
	for(int i = 1; i <= n; i ++) {
		scanf("%lld", &ki);
		for(int j = 1; j <= ki; j ++) {
			scanf("%lld%lld", &aij, &tij);
			xian[i].push_back({aij, tij});
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j < (int)xian[i].size(); j ++) {
			dtz[xian[i][j - 1].aik].push_back({i, xian[i][j].aik});
			dtz[xian[i][j].aik].push_back({i, xian[i][j - 1].aik});
		}
	}
	while(q --) {
		scanf("%lld%lld", &xr, &yr);
		ans = 9223372036854775807;
		for(int i = 1; i <= n; i ++) {
			B[i] = false;
		}
		jh(xr, yr, 0, 0);
		printf("%lld\n", ans + w[xr] + w[yr]);
	}
	
	return 0;
}
