//GZ-J00021 贵阳市第一中学  郑淇予
#include<bits/stdc++.h>
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define ll long long
using namespace std;
const int N = 200005;
ll start[2][N];
char c[2][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll len = 0;
	int n;
	cin >> n;
	FOR(i, 1, n){
		int a;
		cin >> a >> c[0][i];
		start[0][i] = len+1;
		len += a;
	}
	start[0][n+1] = len+1;
	FOR(i, 1, n){
		start[1][i] = len-start[0][n-i+2]+2;
		c[1][i] = c[0][n-i+1];
		//cout << i << '#' << c[1][i] << '#' << start[1][i] << endl;
	}
	start[1][n+1] = len+1;
	int l = 1, r = 1, ls = 0, rs = 1;
	ll ans = 0;
	while(start[ls][l] <= len/2 && start[rs][r] <= len/2){
		//cout << ls << '#' << l << ' ' << rs << '#' << r << endl;
		if(start[ls][l+1] < start[rs][r+1]){
			swap(ls, rs);
			swap(l, r);
			continue;
		}
		if(c[rs][r] != c[ls][l]){
			ans += start[rs][r+1] - max(start[ls][l], start[rs][r]);
		}
		r++;
	}
	cout << ans;
	return 0;
}
