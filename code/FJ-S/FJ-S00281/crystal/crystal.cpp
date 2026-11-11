#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;

int n, m;
int a[N], sum[N];
int ans;

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return f * x;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; ++i) a[i] = read();
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	for(int i = 1; i <= n; ++i){
		int u = a[i];
		int L = 1, R = i;
		while(L < R){
			int mid = L + R + 1 >> 1;
			int res = mid * u - (sum[i] - sum[i - mid]);
//			printf("%d %d  %d - %d\n", u, mid, mid * u, (sum[i] - sum[i - mid]));
			if(res <= m) L = mid;
			else R = mid - 1;
		}
		ans = max(ans, L);
	}
	printf("%lld\n", ans);
	return 0;
}


/*
目标能量必然为ai中的一个 
0 2 5 5 10
枚举目标能量ak,二分长度t 
需要加((t-1)*ak - (sum[k]-sum[k-t]))  <=m

5 5
1 2 4 8 9
*/
