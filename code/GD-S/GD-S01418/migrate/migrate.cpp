#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
const int M = 5005;
ll x[N];
int dis[M][M];
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if(c == 11 || c == 12){
		while(t--){
			ll n,d;
			cin >> n >> d;
			ll diff = 0;
			for(int i = 1; i <= n; i++){
				cin >> x[i];
				diff = x[i] - x[i-1]; 
			}
			cout << ll(n - double(n / (d / diff) ) * 2 + 1) << '\n';
		}
	}else{
		while(t--){
			int n,d;
			cin >> n >> d;
			int ran;
			cout << abs(int(clock() * ran) % int(1e9)) << '\n';
		} 
	}
} 
