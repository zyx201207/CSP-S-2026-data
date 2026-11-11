#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, t;
int n, d;
int a[N];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while(t -- ){
		cin >> n >> d;
		for(int i = 1; i <= n; i ++ ){
			cin >> a[i];
		}
		int l = 1, r = n, ans = 0, t = 0;
		for(int k = 2; ; ){
			if(k == n - 1 && r == n && l == n - 2) break;
			else if(r == k + 1){
				r = n;
				l ++ ;
			}
			if(a[k] - a[l] <= d && a[r] - a[k] <= d && t != 0){
				ans ++ ;
				k ++ ;
				t = 0;
			}
			else if(a[k] - a[l] <= d && a[r] - a[k] <= d && t == 0){
				t = 1;
				r -- ;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 

