#include <bits/stdc++.h>
using namespace std;
const int _ = 500010;
int n, ans;
long long us, m, a[_];
inline bool bbb(int x, int y){
	return x > y;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crytal.out", "w", stdout);
	ios :: sync_with_stdio(0), cin. tie(0), cout. tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, bbb);
	int R = 1;
	for(int i = 1; i <= n; i ++){
		if(a[1] - a[i] + us <= m){
			us += a[1] - a[i];
		}
		else{
			ans = max(ans, i);
			R = i - 1;
			break;
		}
	}
	if(! R){
		cout << n;
		return 0;
	}
	for(int i = 2; i <= n; i ++){
//		int j = i;
//		while(a[j + 1] == a[i]){
//			j ++;
//		}
		long long h = (a[i - 1] - a[i]) * (R - i + 1);
		us -= h;
		while(R < n && us + a[i] - a[R + 1] <= m){
			us += a[i] - a[R + 1];
			R ++;
		}
		ans = max(ans, R - i + 1);
		if(R >= n){
			break;
		}
//		cout<<i<<' '<<R<<'\n';
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

*/
/*
5 8
-3 -1 2  2 7

*/
