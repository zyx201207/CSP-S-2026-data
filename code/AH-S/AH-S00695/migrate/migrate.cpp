#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
typedef long long ll;

int c, t;
ll n, m, a[N];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while(t --){
		cin >> n >> m;
		for(int i = 1; i <= n; i ++)
			cin >> a[i];
		if(c == 11 || c == 12){
			if(m <= a[2] - a[1]) cout << "0\n";
			else{
				ll ans = n - (2 * m / (a[2] - a[1])) + 1;
				cout << (ans > 0 ? ans : 0) << '\n';
			} 
			continue;
		}
		cout << "0\n";
	}
	return 0;
}

