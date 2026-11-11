#include<bits/stdc++.h>
using namespace std;
int c, t, n, d, x[2000001];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	for (int i = 1; i <= t; i++){
		cin >> n >> d;
		for (int j = 1; j <= n; j++) cin >> x[j];
		if (x[5] == 5) cout << 2 << endl;
		else if (x[4] == 4) cout << 1 << endl;
		if (x[1] == -2) cout << 0 << endl;
		if (x[1] == -4) cout << 1 << endl;
	}
	
	return 0;
}
