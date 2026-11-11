#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int t, c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> t >> c;
	while(t--){
		int n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		int ans = 0;
		if(a[2] - a[1] < d){
			for(int i = 4; i <= n; i+= 2){
				ans += n - i;
			}
			cout << ans << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}
