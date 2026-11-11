#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		int x;
		cin >> x;
		sum += x;
		
	}
	while (q--){
		cout << sum << endl;
	}
	return 0;
} 
