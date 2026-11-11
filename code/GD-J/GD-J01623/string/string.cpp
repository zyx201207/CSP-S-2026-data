#include <bits/stdc++.h>
using namespace std;

const int M = 1 << 20;
char buf[M];
int len, pos;
inline int gc(){
	if(len == pos){
		pos = 0;
		len = fread(buf, 1, M, stdin);
		if(len == 0) return EOF;
	}
	return buf[pos++];
}
inline int read(){
	int s(0), t(1), c = gc();
	for(;c != EOF && (c < '0' || c > '9');c = gc()) if(c == '-') t = -1;
	if(c == EOF) return 0;
	for(;c >= '0' && c <= '9';c = gc()) s = (s << 3)+(s << 1)+(c ^ 48);
	return s*t;
}

long long a[1000005];
char c[1000005];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, tot(0); n = read();
	for(int i = 1;i <= n;i++){
		a[i] = read(); c[i] = gc();
		tot += a[i];		
	}
	long long l(1), r(n), p(0);
	long long sum1(a[l]), sum2(a[r]), ans(0);
	while(l < r){
		if(c[l] != c[r])
			ans += min(sum1, sum2)-p;
		p = min(sum1, sum2);
		if(sum1 <= p && sum1 <= tot/2)
			sum1 = min(tot/2, sum1+a[++l]);
		if(sum2 <= p && sum2 <= tot/2)
			sum2 = min(tot/2, sum2+a[--r]);
	}
	cout << ans;
}
