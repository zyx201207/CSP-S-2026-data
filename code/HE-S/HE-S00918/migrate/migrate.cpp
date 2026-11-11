#include <bits/stdc++.h>
using namespace std;

#define int long long

int c, t;
int n, d;
const int N = 2e6 + 5;

int ans;
int x[N];
inline void hdkk(int now, int r, int cnt, int& a, int& b){
	if(now == r){
		if(cnt < a){
			a = cnt, b = 1;
		}
		else if(cnt == a)   b ++;
		return ;
	}
	for(int i = now + 1;i <= r;i ++){
		if(x[i] - x[now] <= d)	hdkk(i, r, cnt + 1, a, b); 
	}
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> c >> t ;
	if(c > 2){
		while(t --)   cout << "0\n";
		exit(0);
	}
	while(t --){
		int ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i ++)   cin >> x[i];
		for(int i = 1;i <= n;i ++){
			for(int j = i + 1;j <= n;j ++){
				int a = INT_MAX, b = 0;
				hdkk(i, j, 0, a, b);
				if(b == 2)   ans ++;
			}
		}
		cout << ans << "\n";
	}
}
