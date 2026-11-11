#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, m, a[MAXN], s[MAXN];
int read(){
	int s = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') s = s * 10 + (ch - '0'), ch = getchar();
	return s;
}
int dfs(int la, int lev, int tem){
	if(lev == m) return tem;
	int ans = 0;
	for(int i = la + 1;i <= n;++i) ans = max(ans, dfs(i, lev + 1, tem & a[i]));
	return ans;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	n = read(), m = read();
	a[1] = read(), s[1] = a[1];
	for(int i = 2;i <= n;++i) a[i] = read(), s[i] = s[i - 1] & a[i];
	sort(a + 1,a + n + 1,greater<int>());
	if(m == 1){
		printf("%d\n", a[1]);
		return 0;
	}
	if(m == n){
		printf("%d\n", s[n]);
		return 0;
	}
	if(m == 2){
		int t = 0;
		for(int i = 1;i < n;++i)
		for(int j = i + 1;j <= n;++j)
		t = max(t, a[i] & a[j]);
		printf("%d\n", t);
		return 0;		
	}
	int ans = 0;
	for(int i = 1;i <= n - m + 1;++i) ans = max(ans, dfs(i, 1, a[i])); 
	printf("%d\n", ans);
	return 0;
}
