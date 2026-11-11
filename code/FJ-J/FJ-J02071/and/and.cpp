#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long ans = -1;
bool vis[2005];
long long a1[2005];
struct Node{
	long long v, cnt, id;
}a[200005];
long long tongji(long long k, long long cnt) {
	if(k == 1) return 1;
	else if(k == 0) return 0;
	else if(k/cnt == 1) return 1+tongji(k%cnt,cnt/2);
	else cnt /= 2;
}
void dfs(int k) {
	if(k > m) {
		long long sum = a1[1];
		for(int i = 2;i <= m;i++) sum &= a1[i];
		ans = max(ans,sum);
	}
	for(int i = 1;i <= n;i++) if(!vis[i]) {
		a1[k] = a[i].v;
		vis[i] = true;
		dfs(k+1);
		vis[i] = false;
	}
}
void f2() {
	for(int i = 1;i <= n;i++) cin >> a[i].v;
	dfs(1);
	cout << ans;
}
void f1() {
	for(int i = 1;i <= n;i++) {
		cin >> a[i].v;
		long long num = 1, j = 1;
		while(a[i].v >= 2*num) num *= 2, j++;
		a[i].id = j;
		a[i].cnt = tongji(a[i].v,num);
	}
	sort(a+1,a+n+1,[](Node a,Node b) {
		if(a.cnt != b.cnt) return a.cnt > b.cnt;
		return a.id < b.id;
	});
	ans = a[1].v;
	for(int i = 2;i <= m;i++) ans &= a[i].v;
	cout << ans;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if(n <= 20) f2();
	else f1();
	
	return 0;
}
