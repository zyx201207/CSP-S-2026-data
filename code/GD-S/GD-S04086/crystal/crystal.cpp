#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5 * 1e5 + 10;
int n, m;
int a[N], s[N];
int x, c;
int ans = 0, cnt = 0, sum = 0;

bool flag(int xzr){
	int i = xzr;
	while(i <= n){
		ans = a[i] * xzr;
		cnt = s[i] - s[i - xzr];
		sum = ans - cnt;
		if(sum <= m) {
			return true;
		}
		i++;
	}
	return false;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	x = 1, c = n;
	while(x < c){
		int l = (x + c + 1) / 2;
		if(flag(l)){
			x = l;
		} else {
			c = l - 1;
		}
	}
	cout << x << endl;
	return 0;
}
