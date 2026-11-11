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
	const int N = 5e2 + 10, M = 5e5 + 10;
	int c, n, m, d, q; 
	int a[M];
	vector<pair<int, int>> v[M + N];
	long long w[N][N];
	int main(){
//		freopen("subway7.in", "r", stdin);
		freopen("subway.in", "r", stdin);
		freopen("subway.out", "w", stdout);
		c = u_read(), n = u_read(), m = u_read(), d = u_read(), q = u_read();
		for(int i = 1; i <= m; ++ i){
			a[i] = u_read();
		} 
		for(int i = 1; i <= n; ++ i){
			int k = u_read();
			for(int j = 1; j <= k; ++ j){
				int x = u_read(), y = u_read();
				v[i + m].emplace_back(x, y);
				v[x].emplace_back(i + m, y);
			}
		}
		memset(w, 0x3f, sizeof(w));
		for(int i = 1; i <= m; ++ i){
			int t = v[i].size();
			for(int j = 1; j < t; ++ j){
				for(int k = 0; k < j; ++ k){
					//k,j
					int t1 = v[i][j].first, t2 = v[i][k].first;
					long long t3 = v[i][j].second + v[i][k].second;
					w[t1 - m][t2 - m] = min(w[t1 - m][t2 - m], t3);
					w[t2 - m][t1 - m] = min(w[t2 - m][t1 - m], t3);
				}
			}
		}
		for(int i = 1; i <= n; ++ i) w[i][i] = 0;
		for(int k = 1; k <= n; ++ k){
			for(int i = 1; i <= n; ++ i){
				for(int j = 1; j <= n; ++ j){
					w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
				}
			}
		}
		while(q --){
			int x = u_read(), y = u_read();
			long long ans = 1e18;
			for(auto i : v[x]){
				for(auto j : v[y]){
					ans = min(ans, w[i.first - m][j.first - m] + i.second + j.second);
				}
			}
			ans += a[x] + a[y];
			u_writell(ans), pc('\n');
		}
		flush();
		return 0;
	}
}
int main(){
	return cqsunny::main();
}
