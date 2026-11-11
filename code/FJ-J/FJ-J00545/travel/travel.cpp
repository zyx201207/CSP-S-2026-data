#include <bits/stdc++.h>
#define int long long
using namespace std;
int rx, xx;
string ry, xy;
bool flag, check[6];
bool f1, f2, f3;
bool check3(){
	if(check[0] && check[1]){
		flag = 1;
		return 1;
	}
	else if(check[0] && check[2]) return 1;
	else if(check[1] && check[2]){
		flag = 1;
		return 1;
	}
	else if(check[3] && check[4]){
		flag = 1;
		return 1;
	}
	return 0;
}
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> rx >> ry >> xx >> xy;
	check[ry[2] - 'A'] = 1;
	check[xy[2] - 'A'] = 1;
	if(rx == xx) f1 = 1, cout << 1;
	else cout << 0;
	if(f1 && ry[0] == xy[0] && ry[1] == xy[1]) f2 = 1, cout << 1;
	else cout << 0;
	if(f1 && f2 && check3()) f3 = 1, cout << 1;
	else cout << 0;
	if(f1 && f2 && f3 && flag) cout << 1;
	else cout << 0;
	return 0;
}
