#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 2;
int s[maxn];
int c, t, n, m;
int flag1;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			cin >> s[i];
			if(i > 2 && s[i] - s[i - 1] != s[i - 1] - s[i - 2])
				flag1 = 1;
		}
		if(!flag1){
			int k = m / (s[2] - s[1]);
			if(k == 1 || 2 * k > n){
				cout << 0 << '\n';
				continue;
			}
			cout << n - 2 * k + 1 << '\n';
			continue;
		}
		else
			cout << 0 << '\n';
	}
	return 0;
}
//Oct31==Dec25?
