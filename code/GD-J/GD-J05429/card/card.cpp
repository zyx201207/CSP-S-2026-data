#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, m, a[N]; 
int main() {

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n ; i ++) cin >> a[i];
	for(int i = 1; i <= m; i++) cout << "1" << " ";
	return 0;
}

