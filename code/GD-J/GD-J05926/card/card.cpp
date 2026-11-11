#include <bits/stdc++.h>
using namespace std;
int n, a[500005], m, k, ds[300005];
map<int, int> wz;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out, "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		wz[a[i]] = i;
	}
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			ds[a[j]]++;
			j = wz[a[j]];
		}
	}
	for (int i = 1; i <= m; i++) cout << ds[i] << " ";
	return 0;
}
