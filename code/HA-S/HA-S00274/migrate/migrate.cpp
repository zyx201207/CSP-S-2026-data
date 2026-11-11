#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 10;
int C, T;
int n, d, ans;
int x[N];



signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> C >> T;
	while(T --){
		cin >> n >> d;
		int t;
		bool b = 1;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
			if(i == 2) t = x[2] - x[1];
			else if(i > 2){
				if(b == 1 && t != (x[i] - x[i - 1])) b = 0;
			}
		}
		if(b == 1){
			if(d < 2 * t || d >= 3 * t){
				cout << 0 << endl;
				continue;
			}
			else{
				cout << n - 3;
				continue;
			}
		}
		
	}
	
	
	
	
	return 0;
}
