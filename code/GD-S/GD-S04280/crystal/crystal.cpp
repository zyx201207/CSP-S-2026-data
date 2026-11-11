#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 7;
int n, m, j = 1, cnt;
int a[MAXN], s[MAXN], maxn, su[MAXN];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i] - a[i - 1];
	for(int i = 1; i <= n; i++)su[i] = su[i - 1] + s[i];
	for(int i = 1; i <= n; i++){
		if((i - j) * s[i] - (su[i] - su[j]) <= m)maxn = max(maxn, i - j);
		else while((i - j) * s[i] - (su[i] - su[j]) > m)j++;
	}
	cout << maxn;
	return 0;
}
