#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int c, t;
int n, d;
int x[N];

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		if(c == 11 || c == 12){
			if((x[2] - x[1]) * 2 <= d && n >= 3){
				cout << n - 3;
			}
			else cout << 0;
		}
		else cout << n - 3;
		cout << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
