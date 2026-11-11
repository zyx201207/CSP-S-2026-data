#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
const int MAXN = 2e5 + 5;

int n, s[MAXN];
char c[MAXN];
ull size, ans;

int read(){
	int s = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') s = s * 10 + (ch - '0'), ch = getchar();
	return s;
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	n = read();
	for(int i = 1;i <= n;++i){
		s[i] = read();
		scanf("%c", &c[i]);
		size += s[i];
	}
	int l = 1, r = n;
	while(l < r && size){
		int t = min(s[l], s[r]);
		if(c[l] != c[r]) ans += t;
		s[l] -= t, s[r] -= t, size -= 2ull * t;
		while(s[l] == 0) ++l;
		while(s[r] == 0) --r;
	}	
	printf("%lld", ans);
	return 0;
}
