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
	const int N = 2e6 + 10;
	int c, T, n;
	long long d, a[N];
	long long f[2010][2010];
	int nxt[N];
	bool fl[2010], fr[2010];
	vector<int> v[2010];
	bool check(){
		for(int i = 3; i <= n; ++ i){
			if(a[i] - a[i - 1] != a[2] - a[1]) return 0;
		}
		return 1;
	}
	int main(){
//		freopen("migrate4.in", "r", stdin);
		freopen("migrate.in", "r", stdin);
		freopen("migrate.out", "w", stdout);
		c = u_read(), T = u_read();
		while(T --){
			n = u_read(), d = u_readll();
			for(int i = 1; i <= n; ++ i) a[i] = readll();
			if(check()){
//				cerr << d << ' ' << a[2] - a[1] << ' ' << n << '\n';
				d /= a[2] - a[1];
				if(d <= 1 || d > n) pc(48), pc('\n'); 
				//2*d-1
				else u_write(max(0ll, n - 2 * d + 1)), pc('\n');
				continue;
			}
			for(int i = 1; i <= n; ++ i) v[i].clear(); 
			int ps = 1;
			for(int i = 1; i < n; ++ i){
				while(ps <= n && a[ps] - a[i] <= d) ++ ps;
				nxt[i] = ps - 1;
			}
			nxt[n] = n;
			for(int i = 1; i < n; ++ i){
//				printf("%d %d\n", i, nxt[i]);
				int t = i, s = 0;
				while(1){
					int p = nxt[t];
					if(t == p){
						for(int j = t + 1; j <= n; ++ j){
							f[i][j] = -1;
						}
						break;
					}
					v[i].emplace_back(p);
//					printf("%d %d\n", i, p);
					++ s;
					for(int j = t + 1; j <= p; ++ j){
						f[i][j] = s;
					}
					t = p;
				}
			}
			int ans = 0;
//			for(int i = 1; i <= n; ++ i){
//				printf("%d %d\n", i, fr[i]); 
//			}
			for(int i = 1; i <= n; ++ i){
				auto t = v[i].begin();
				for(int j = i; j <= n; ++ j){
//					printf("%d %d %d\n", i, j, f[i][j]);
					if(f[i][j] == -1) break;
					if(t != v[i].end() && (*t) == j){
						fl[j] = 1;
						++ t;
//						printf("%d %d\n", i, j); 
					}
					int p = 0;
					for(int k = i + 1; k < j; ++ k){
						if(!fl[k] && !fr[k] && f[i][k] + f[k][j] == f[i][j]){
//							printf("%d %d %d %d %d\n", i, j, k, f[i][k], f[k][j]);
							if(!p){
								p = k;
								fr[k] = 1;
								for(auto l : v[k]){
									if(l >= j) break;
									fr[l] = 1;
								}
							}
							else{
								p = -p;
								break;
							}
						}
					}
//					printf("%d %d %d\n", i, j, p);
					if(p > 0 || p < 0){
						if(p < 0) p = -p;
						else ++ ans;
						fr[p] = 0;
						for(auto l : v[p]){
							if(l >= j) break;
							fr[l] = 0;
						}
					}
				} 
				for(auto j : v[i]) fl[j] = 0;
			}
			u_write(ans), pc('\n');
		}
		flush();
		return 0;
	}
}
int main(){
	return cqsunny::main();
}
