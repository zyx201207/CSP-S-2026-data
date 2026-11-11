#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 5e5 + 5;
int n, m, a[maxn], ans[maxn];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	vector<int> v;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		int c[maxn] = {};
		for (int j = i; j <= n; j++){
			if (c[a[j]] == 0){
				v.push_back(a[j]);
			}
			else {
				while (v[v.size()] != a[j]) v.pop_back();
				v.push_back(a[j]);
			}
		}
		for (int r = 1; r <= v.size(); r++){
			ans[v[r]]++;
		}
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i];
	}
	return 0;
}
