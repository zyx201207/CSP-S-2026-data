#include <bits/stdc++.h>
#define int long long
#define il inline
#define pb push_back
using namespace std;
const int N = 2e6+10;

int c, T;
int n, d, a[N];

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		int D = 0;
		bool A = 1, B = 0;
		int Bcnt = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			if(i == 2) D = a[i] - a[i - 1];
			if(i > 2){
				if(a[i] - a[i - 1] != D) B = 0;
			}
			if(a[n] - a[i] <= d && a[i] - a[1] <= d){
				B = 1;
				Bcnt++;
			}
		}
		if(A){
			if(d < D){
				cout << 0 << '\n';
				continue;
			}
			int mx = d / D;
			if(mx >= n){
				cout << 0 << '\n';
				continue;
			}
			int R = 1 + mx * 2 - 1, cnt = mx - 1;
			if(R > n){
				cout << 0 << '\n'; continue;
			} 
			cout << (n - R + 1) * cnt << '\n';
			continue;
		}
		cout << 0 << '\n';
	}
	return 0;
}
