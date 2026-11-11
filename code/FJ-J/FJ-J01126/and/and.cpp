#include<bits/stdc++.h>
using namespace std;
int n, m;
struct node{
	long long x;
	int c;
}a[200005];
long long sum;
void f(int id){
	long long t = a[id].x;
	while(t){
		int s = t % 2;
		t /= 2;
		if (s == 1)a[id].c++;
	}
	return;
}
bool cmp(node a, node b){
	if (a.c != b.c)return a.c > b.c;
	return a.x > b.x;
}
long long maxx = 0;
int b[200005];
void dfs(int s, long long sum){
	if (s > m){
		maxx = max(maxx, sum);
		return;
	}
	for (int i = 1; i <= n; i++){
		if (b[i] == 0){
			b[i] = 1;
			if (s == 1)dfs(s + 1, a[i].x);
			else dfs(s + 1, (sum & a[i].x));
			b[i] = 0;
		}
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i].x;
	}
	if (n <= 2000){
		dfs(1, 0);
		cout << maxx;
		return 0;
	}
	for (int i = 1; i <= n; i++){
		f(i);
	}
	sort(a + 1, a + n + 1, cmp);
	sum = a[1].x;
	for (int i = 2; i <= m; i++){
		sum &= a[i].x;
//		cout << a[i].x << " " << sum << '\n';
	}
	cout << sum;
	return 0;
}
