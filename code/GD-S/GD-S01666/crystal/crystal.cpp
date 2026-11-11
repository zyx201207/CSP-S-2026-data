#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LL long long

LL read(){LL x; scanf("%lld", &x); return x; }

const int N = 5e5 + 100;

int n, m;
int a[N];

int ans;
int um;

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read(); m = read();
	for(int i = 1; i <= n; i ++)a[i] = read();
	
	sort(a + 1, a + 1 + n);
	int j = 1;
	for(int i = 1; i <= n; i ++){
		um += (i - j) * (a[i] - a[i - 1]);
		while(um > m)um -= a[i] - a[j], j ++;
		ans = max(i - j + 1, ans);
	}
	
	printf("%lld", ans);
	
	return 0;
}
