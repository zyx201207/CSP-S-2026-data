#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int cnt[300005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		vector<int> in;
		for (int j = i; j <= n; j ++) {
			int k;
			for (k = 0; k < in.size(); k ++)
				if (in[k] == a[j])
					break;		
			in.erase(in.begin() + k, in.end());
			in.push_back(a[j]);
		}
		for (const auto& v : in)
			cnt[v] ++;
	}
	for (int i = 1; i <= m; i ++)
		cout << cnt[i] << " ";
	cout << endl;
	return 0;
}