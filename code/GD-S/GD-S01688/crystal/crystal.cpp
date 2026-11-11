#include <bits/stdc++.h>
using namespace std;
const int M = 1 << 20;
char buf[M];
int buf_len, buf_pos;
inline int gc(){
	if(buf_len == buf_pos){
		buf_pos = 0;
		buf_len = fread(buf, 1, M, stdin);
		if(buf_len == 0) return EOF;
	}
	return buf[buf_pos++];
}
inline int read(){
	int s(0), t(1), c = gc();
	for(;c != EOF && (c < '0' || c > '9');c = gc()) if(c == '-') t = -1;
	if(c == EOF) return 0;
	for(;c >= '0' && c <= '9';c = gc()) s = (s << 3)+(s << 1)+(c ^ 48);
	return t*s;
}

const int N = 1000005;
long long n, m, a[N], s[N];
bool cmp(const long long &x, const long long &y){
	return x > y;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1;i <= n;i++)
		a[i] = read();
	sort(a+1, a+n+1, cmp); 
	for(int i = 1;i <= n;i++)
		s[i] = s[i-1]+a[i];
	
	long long ans(0);
	for(int i = 1;i < n;i++){
		if(a[i]-a[i+1] > m)
			continue;		
		long long l = 1, r = n-i;
		while(l < r){
			long long mid = ((l+r) >> 1)+1;
			if(mid*a[i]-(s[i+mid]-s[i]) <= m)
				l = mid;
			else
				r = mid-1;
		}
		ans = max(ans, l+1);
	}
	cout << ans;
} 
