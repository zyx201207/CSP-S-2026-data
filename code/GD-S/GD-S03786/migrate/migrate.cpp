#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2 + 10;
int c , T;
int a[N];
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout); 
	cin >> c >> T;
	while(T--){
		int n;
		ll ans = 0;
		ll d , x;
		cin >> n >> d;
		for(int i = 1;i <= n;++i){
			cin >> a[i];
			if(i == 2) x = a[i] - a[i - 1];
		}
		if(d <= x){
			cout << "0\n";
			continue;
		}
		for(int len = 4;len <= n;len += 2){
			for(int i = 1;i + len - 1 <= n;++i){
				int j = i + len - 1;
				if(abs(a[j] - a[i]) <= d) continue;
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
