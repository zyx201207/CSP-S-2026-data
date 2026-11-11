#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, m, a[N], b[N];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[a[i]] = i;
	}
	for (int i = 1; i <= m; i++) cout << b[i] << " ";
	return 0;
}
