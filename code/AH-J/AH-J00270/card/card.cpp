#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 5, MAXM = 3e5 + 5;
int n, m, a[MAXN], f[MAXM], t[MAXN], len;

int read(){
	int s = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') s = s * 10 + (ch - '0'), ch = getchar();
	return s;
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	n = read(), m = read();
	for(int i = 1;i <= n;++i) a[i] = read();
	for(int i = 1;i <= n;++i){
		len = 0;
		for(int j = i;j <= n;++j){
			int ttt = 0;
			for(;t[ttt] != a[j] && ttt < len;) ++ttt;
			len = ttt;
			t[len++] = a[j];
		}
		for(int j = 0;j < len;++j) ++f[t[j]];
	}
	for(int i = 1;i <= m;++i) printf("%d ",f[i]);
	return 0;
}
