#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c , t , n , d;
	cin >> c >> t;
	while(t --){
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i];
		}
		cout << n - 1 << endl;
	}
	return 0;
}
