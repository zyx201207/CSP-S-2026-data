#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int n, m;
int a[N];
bool st[N];
vector<int> num;
int ans[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) {
		memset(st, 0, sizeof st);
		num.clear();
		
		for (int j = i; j <= n; j ++) 
			if (!st[a[j]]) st[a[j]] = 1, num.push_back(a[j]);
			else while (num.back() != a[j]) st[num.back()] = 0, num.pop_back();
		
		for (auto x : num) ans[x] ++;
	}
	
	for (int i = 1; i <= m; i ++) printf("%d ", ans[i]);
	
	return 0;
} 
