#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t, n, d, x[N];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		sort(x + 1, x + 1 + n);
		if(c == 11 || c == 12){
			long long cha = x[2] - x[1], sum = 0, cnt = 0;
			for(int i = 1; i <= n; i++) {
				sum += cha;
				if(sum > d){
					cnt = i;
					break;
				} 
			}
			if(cnt <= 1 || cnt > n / 2) cout << 0 << "\n";
			else{
				int len = 2 * cnt + 1;
				int ans = n - len + 1;
				cout << ans << "\n";
			}
		}
	}
	return 0;
}