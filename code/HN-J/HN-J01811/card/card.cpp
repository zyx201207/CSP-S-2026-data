#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int a[N];
int q[N];
int n, m;
int ans[N];
bool pos[M];
inline int read() {
	char ch;
	while(!isdigit(ch = getchar()));
	int res = ch ^ 48;
	while(isdigit(ch = getchar()))
		res = (res << 1) + (res << 3) + (ch ^ 48);
	return res;
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n = read(), m = read();
	bool A = true;
	for(int i = 1; i <= n; ++i)
		a[i] = read(), A &= (a[i - 1] <= a[i]);
	if(A) {
		int pos = 0;
		for(int i = 1; i <= n; ++i)
			if(a[i] != a[i + 1])
				ans[a[i]] = i;
		for(int i = 1; i <= m; ++i)
			cout << ans[i] << ' ';
	}
	else {
		for(int i = 1; i <= n; ++i) {
			int now = 0;
			for(int j = i; j <= n; ++j)
				if(!pos[a[j]]) pos[a[j]] = true, q[++now] = a[j];
				else {
					while(q[now] != a[j])
						pos[q[now--]] = false;
					q[now] = a[j];
				}
			for(int j = 1; j <= m; ++j)
				ans[j] += pos[j], pos[j] = false;
		}
		for(int i = 1; i <= m; ++i)
			cout << ans[i] << ' ';	
	}
	return 0;
}//52
