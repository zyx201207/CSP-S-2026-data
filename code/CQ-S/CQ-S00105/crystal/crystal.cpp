#include<bits/stdc++.h>
using namespace std;
namespace rm{
	const int maxsize = 1 << 20, maxsize2 = 1 << 18;
	char inbuf[maxsize], outbuf[maxsize2], *p1 = inbuf, *p2 = inbuf, *p3 = outbuf;
	#define gc() (p1 == p2 ? (p2 = (p1 = inbuf) + fread(inbuf, 1, maxsize, stdin), p1 == p2 ? EOF : *p1 ++) : *p1 ++)
	#define pc(ch) ((p3 == outbuf + maxsize2) && (fwrite(outbuf, 1, maxsize2, stdout), p3 = outbuf), *p3 ++ = ch)
	#define flush() (fwrite(outbuf, 1, p3 - outbuf, stdout), p3 = outbuf)
	int u_read(){
		char ch = gc(); int x = 0;
		while(ch < 48 || ch > 57) ch = gc();
		while(ch >= 48 && ch <= 57) x = (x << 3) + (x << 1) + (ch ^ 48), ch = gc();
		return x;
	}
	long long u_readll(){
		char ch = gc(); long long x = 0;
		while(ch < 48 || ch > 57) ch = gc();
		while(ch >= 48 && ch <= 57) x = x * 10 + (ch ^ 48), ch = gc();
		return x;
	}
	int read(){
		char ch = gc(); int x = 0; bool f = 0;
		while(ch < 48 || ch > 57) f |= ch == 45, ch = gc();
		while(ch >= 48 && ch <= 57) x = (x << 3) + (x << 1) + (ch ^ 48), ch = gc();
		return f ? -x : x;
	}
	long long readll(){
		char ch = gc(); long long x = 0; bool f = 0;
		while(ch < 48 || ch > 57) f |= ch == 45, ch = gc();
		while(ch >= 48 && ch <= 57) x = x * 10 + (ch ^ 48), ch = gc();
		return f ? -x : x;
	}
	void u_write(int x){
		int stk[10], tp = 0;
		while(x) stk[tp ++] = x % 10, x /= 10;
		if(!tp) pc(48);
		else while(tp --) pc(stk[tp] + 48);
	}
	void u_writell(long long x){
		int stk[20], tp = 0;
		while(x) stk[tp ++] = x % 10, x /= 10;
		if(!tp) pc(48);
		else while(tp --) pc(stk[tp] + 48);
	}
	void write(int x){
		if(x < 0) pc(45), x = -x;
		int stk[10], tp = 0;
		while(x) stk[tp ++] = x % 10, x /= 10;
		if(!tp) pc(48);
		else while(tp --) pc(stk[tp] + 48);
	}
}
namespace cqsunny{
	using namespace rm;
	const int N = 5e5 + 10;
	int n;
	long long m;
	long long a[N];
	int main(){
//		freopen("crystal4.in", "r", stdin);
		freopen("crystal.in", "r", stdin);
		freopen("crystal.out", "w", stdout);
		n = u_read(), m = u_readll();
		for(int i = 1; i <= n; ++ i) a[i] = readll();
		sort(a + 1, a + n + 1);
		int ps = 1, ans = 0;
		long long nw = a[1], sum = 0;
		for(int i = 1; i <= n; ++ i){
//			printf("%d %d %d %d\n", i, sum, a[i], nw);
			if(nw < a[i]){
				long long t = 1ll * (a[i] - nw) * (i - ps);
				if(m < sum + t){
					while(ps < i){
						sum -= nw - a[ps];
						t -= a[i] - nw;
						++ ps;
						if(sum + t <= m){
							sum += t;
							break;
						}
					}
				}
				else{
					sum += t;
				}
				nw = a[i];
			}
			ans = max(ans, i - ps + 1);
		}
		printf("%d", ans);
		flush();
		return 0;
	}
}
int main(){
	return cqsunny::main();
}
