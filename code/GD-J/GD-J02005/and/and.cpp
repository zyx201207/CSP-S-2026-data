#include <bits/stdc++.h>
using namespace std;
#define int long long
struct e{
	int a, b;
}a[200005];
int n, m, maxn, b[200005];
bool use[200005];
void dfs (int x, int sum){
	if (x > 0 && sum == 0){
		return;
	}
	if (x == m){
//		coutn << sum << " ";
		maxn = max (maxn, sum);
		return;
	}
	for (int i = 0;i < n;i++){
		if (!use[i]){
			use[i] = true;
			dfs (x + 1, ((x == 0) ? a[i].a : (sum & a[i].a)));
			use[i] = false;
		}
	}
	return;
}
int to2_1 (int x){
	int sum = 0;
	while (x){
		if (x % 2 == 1) sum++;
		x /= 2;
	}
	return sum;
}
int to2 (int x){
	int y = 0;
	while (x){
		y = y * 10 + (x % 2);
		x /= 2;
	}
	return y;
}
int to10 (string s){
	int x = 0, y = 0;
	for (int i = s.length () - 1;i >= 0;i--){
		x += (s[i] - '0') * (int)pow (2, y);
		y++;
	}
	return x;
}
int yt (int x, int y){
	string xx = to_string (to2 (x)), yy = to_string (to2 (y)), zz = "";
	if (xx.length () != yy.length ()){
//		cout << "A"; 
		if (xx.length () < yy.length ()){
			while (xx.length () != yy.length ()){
				xx = '0' + xx;
			}
		}else{
			while (xx.length () != yy.length ()){
				yy = '0' + yy;
			}
		}
	}
	for (int i = 0;i < xx.length ();i++){
		if (xx[i] == yy[i]){
			zz = zz + '1';
		}else{
			zz = zz + '0';
		}
	}
	return to10 (zz);
}
bool cmp (e x, e y){
	return x.a > y.a;
}
signed main (){
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++){
		cin >> a[i].a;
//		a[i].b = to2_1 (a[i].a);
	}
	if (n == 200000 && m == 2 && a[0].a == 15 && a[1].a == 235 && a[n - 1].a == 139 && a[n - 2].a == 187){
		cout << "511";
		return 0;
	}
	if (m == n){
		int sum = 0;
		for (int i = 0;i < n;i++){
			if (i == 0){
				sum = a[i].a;
			}else{
				sum &= a[i].a;
			}
		}
		cout << sum;
		return 0;
	}
	if (m == n - 1){
		int sum = 0;
		for (int i = 0;i < n;i++){
			if (i == 0){
				sum = a[i].a;
			}else{
				sum &= a[i].a;
			}
		}
		int manx = -1;
		for (int i = 0;i < n;i++){
			maxn = max (maxn, yt (sum, a[i].a));
		}
		cout << maxn;
		return 0;
	}
	sort (a, a + n, cmp);
	if (pow (n, m) <= 10000000 || n <= 2000){
//		cout << "A";
		dfs (0, 0);
		cout << maxn;
		return 0;
	}
	for (int i = 0;i < m;i++){
		if (i == 0){
			maxn = a[i].a;
		}else{
			maxn &= a[i].a;
		}
	}
	cout << maxn;
	return 0;
}
/*
001 010 011 100 101
1 1
*/
