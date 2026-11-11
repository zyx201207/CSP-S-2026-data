#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int c, t;
int n, d;
int a[N];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		int cnt = 0;
		cin >> n >> d;
		for(int j = 1;j <= n;j++)cin >> a[j];
		for(int j = 1;j <= n - 2;j++){
			for(int z = j + 2;z <= n;z++){
				if((z - j) % 2 != 0)cnt++;
			}
		}
		cout << cnt;
	}
}

