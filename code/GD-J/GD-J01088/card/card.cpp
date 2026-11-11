#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5 * 1e5 + 78;
int num[MAXN];//答案
int card[MAXN];
int mp[MAXN];//t 值  (里面是下标)
int mpps[MAXN];//上一次出现下标 该数字
bool ct[MAXN];//是否出现 该数字
int ck[MAXN][100];//t对应下标  该数字
//t:出现次数
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}
	for (int i = 1; i <= n; i++) {
		if (ct[card[i]]) {
			mp[i] = mp[mpps[card[i]]] + 1;
			mpps[card[i]] = i;
			ck[card[i]][mp[i]] = i;
		}else {
			ct[card[i]] = true;
			mpps[card[i]] = i;
			ck[card[i]][0] = i;
		}
	}
	bool skp = false;
	for (int T = 1; T <= n; T++) {
		for (int i = T; i <= n; i++) {
			if (skp) {
				num[card[i]]--;
				skp = false;
			}
			if (ck[card[i]][mp[i] + 1] == 0) {
				num[card[i]]++;
				skp = false;
			} else {
				num[card[i]]++;
				i = ck[card[i]][mp[i] + 1] - 1;
				skp = true;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << num[i] << ' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
