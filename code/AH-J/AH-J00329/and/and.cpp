#include<bits/stdc++.h>
using namespace std;
int n, m, a[200010], ans;
void func(int cur, int c, int s){
	if(c == m){ans = max(ans, s);return;}
	if(cur > n)return;
	func(cur + 1, c, s);
	func(cur + 1, c + 1, s & a[cur]);
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n;i++)scanf("%d", a + i);
	func(1, 0, INT_MAX);
	printf("%d", ans);
	return 0;
}
