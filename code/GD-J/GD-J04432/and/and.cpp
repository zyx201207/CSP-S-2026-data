#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define lowbit(x) (x&((~x)+1))
const int N = 2e5 + 3;
int n, m, a[N];
int f[2003][2003];
int qz[N], hz[N];
bool st1, st2, st3, st4;

void wrong_dp(){
	for(int i = 1;i <= n;++i){
		f[i][1] = max(f[i-1][1], a[i]);
	}
	for(int i = 2, tmp;i <= n;++i){
		tmp = min(i, m);
		for(int j = 2;j <= i;++j){
			f[i][j] = f[i-1][j-1]&a[i];
			if(j < i){
				f[i][j] = max(f[i][j], f[i-1][j]);
			}
		}
	}
	cout << f[n][m] << '\n';
	return ;
}

int dfs(int x, int c, int v){
	if(c == m){
		return v;
	}
	if(x == n + 1){
		return -1;
	}
	if(n - x + c + 1 < m){
		return -1;
	}
	int max1, max2;
	if(v == -1) max1 = dfs(x+1, c+1, a[x]);
	else max1 = dfs(x+1, c+1, v&a[x]);
	max2 = dfs(x+1, c, v);
	return max(max1, max2);
}//dfs(1, 0, -1);

void special1(){
	int ans = a[1];
	for(int i = 2;i <= n;++i){
		ans &= a[i];
	}
	cout << ans << '\n';
	return ;
}

void special2(){
	qz[1] = a[1];
	for(int i = 2;i <= n;++i){
		qz[i] = qz[i-1] & a[i];
	}
	hz[n] = a[n];
	for(int i = n-1;i >= 1;--i){
		hz[i] = hz[i+1] & a[i];
	}
	int ans = -1;
	for(int i = 1;i <= n;++i){
		if(i == 1) ans=max(ans, hz[2]);
		if(i == n) ans=max(ans, qz[n-1]);
		ans = max(ans, qz[i-1]&hz[i+1]);
	}
	cout << ans << '\n';
	return ;
}

void special3(){
	sort(a+1, a+n+1);
	int ans = a[n];
	for(int i = n-1;i >= n-m+1;--i){
		ans &= a[i];
	}
	cout << ans;
	return ;
}

void special4(){
	int ans = -1;
	for(int i = 1;i <= n;++i){
		ans = max(ans, a[i]);
	}
	cout << ans << '\n';
	return ;
}

inline bool check(int x){
	return (x+1 == ((x+1)&(0-x-1)));
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	st3 = true;
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
		st3 &= check(a[i]);
	}
	st1 = (m == n);
	st2 = (m == n-1);
	st4 = (m == 1);
	if(n <= 20){
		cout << dfs(1, 0, -1) << '\n';
	}
	else if(st1){
		special1();
	}
	else if(st2){
		special2();
	}
	else if(st3){
		special3();
	}
	else if(st4){
		special4();
	}
	else{
		wrong_dp();
	}
	return 0;
}
