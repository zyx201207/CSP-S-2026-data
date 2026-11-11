#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10 , M = 31;
int a[N] , w[N][M];
vector<int> h[N];
int qpow(int a , int b){
	int ans = 1;
	while(b){
		if(b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}
signed main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , m;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i];
	for(int k = 0 ; k < M ; k ++){
		for(int i = 1 ; i <= n ; i ++){
			if((a[i] >> k) & 1){
				w[i][k] = 1;
			}else{
				w[i][k] = 0;
			}
		} 
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int k = M - 1 ; k >= 0 ; k --){
			h[i].push_back(w[i][k]);
		}
		reverse(h[i].begin() , h[i].end());
	}
	vector<int> g; 
	for(int k = M ; k >= 0 ; k --){
		int cnt = 0;
		for(int i = 1 ; i <= n ; i ++){
			int d = h[i][k];
			if(d == 1){
				bool f = 1;
				for(auto x : g){
					if(h[i][x] != 1) f = false;
				}
				if(f) cnt ++; 
			}else continue;
		}
		if(cnt >= m) g.push_back(k);
	}
	int ans = 0;
	for(auto x : g){
		ans += qpow(2 , x); 
	} 
	cout << ans << '\n';
	return 0;
}

/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
