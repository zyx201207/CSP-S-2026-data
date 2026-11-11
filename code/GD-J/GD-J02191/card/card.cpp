#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	map<int,int> cnt;
	cin >> n >> m;
	vector<int> a(n + 1,0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int game = 1; game <= n; game++) {
		vector<int> cs;
		for (int c = game; c <= n; c++) {
			for (int i = 0; i < cs.size(); i++) {
				if (cs[i] == c) {
					int s = cs.size();
					for (int j = 1; j <= s - i; j++) cs.pop_back();
					break;
				}
			}
			cs.push_back(c);
		}
		for (int c : cs) cnt[c]++;
	}
	for (int i = 1; i <= m; i++) cout << cnt[i] << ' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
