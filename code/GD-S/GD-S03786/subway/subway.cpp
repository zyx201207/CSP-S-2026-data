#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2 + 10;
ll c , n , m , d , q;
ll k[N] , e[N];
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout); 
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;++i){
		cin >> e[i];
	}
	for(int i = 1;i <= n;++i){
		cin >> k[i];
	}
	for(int i = 1;i <= n;++i){
		cout << k[i] + e[i] << '\n';
	}
	return 0;
} 
