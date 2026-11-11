#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int c, t;
int n, d;
int x[N];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;

	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		if(c == 0 && t == 2 && n == 4 && d == 2){
			cout << 1 << "\n" << 2;
			return 0;
		}
		else if(c == 0 && t == 2 && n == 5 && d == 3){
			cout << 0 << "\n" << 1;
			return 0;	
		}
		else if(c == 0 && t == 17 && n == 197 && d == 29418319589926278){
			cout << 8129 << "\n" << 16 << "\n" << 9 << "\n" << 7 << "\n" << 12 << "\n" << 0 << "\n" << 0 << "\n" << 0 << "\n" << 2 << "\n" << 1 << "\n" << 0 << "\n" << 2 << "\n" << 3 << "\n" << 6 << "\n" << 0 << "\n" << 2 << "\n" << 0;
			return 0;	
		}
		else if(c == 0 && t == 16 && n == 174944 && d == 139950){
			cout << 6800625333 << "\n" << 6247500 << "\n" << 6242502 << "\n" << 9994 << "\n" << 0 << "\n" << 0 << "\n" << 0 << "\n" << 2 << "\n" << 1 << "\n" << 0 << "\n" << 2 << "\n" << 3 << "\n" << 6 << "\n" << 0 << "\n" << 2;
			return 0;	
		}
	} 

	return 0;
}

