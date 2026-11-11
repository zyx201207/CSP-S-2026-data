#include <bits/stdc++.h>
using namespace std;
const int N = 500010, M = 200010;
int n, m, ans[N], a[N], mx[N], nxt[N];
vector<int> v[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	bool fl = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i], fl &= a[i - 1] <= a[i];
	if (m == 1)return cout << n, 0;
	if (fl){
		for (int i = 1; i <= n; i ++)
			mx[a[i]] = max(mx[a[i]], i);
		for (int i = 1; i <= m; i ++)
			cout << mx[i] << " ";
		return 0;
	}for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= n; j ++)
			v[j].clear(), nxt[j] = j + 1;
		for (int j = i; j <= n; j ++){
			if (!v[a[j]].size()){
				v[a[j]].push_back(j);continue;
			}int lst = v[a[j]].back();
			for (int k = lst + 1; k < j; k = nxt[k])
				while (v[a[k]].size() && v[a[k]].back() > lst)
					v[a[k]].pop_back();
			nxt[lst] = j;
		}for (int j = 1; j <= m; j ++)
			if (v[j].size())ans[j] ++;
	}for (int i = 1; i <= m; i ++)cout << ans[i] << " ";
	return 0;
}
