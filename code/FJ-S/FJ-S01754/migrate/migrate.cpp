#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
int c, t;
long long a[maxn];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		long long n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		long long cnt = 0;
		for(int i = 1; i <= n - 3; i++){
			if(a[i] + d >= a[i + 2] && a[i + 1] + d >= a[i + 3] && a[i + 3] - a[i] > d) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}
