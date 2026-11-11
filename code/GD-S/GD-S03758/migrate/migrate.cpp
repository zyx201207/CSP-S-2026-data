#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
template<class T>bool ckmax(T &x,const T y){return x<y?x=y,1:0;}
template<class T>bool ckmin(T &x,const T y){return x>y?x=y,1:0;}
inline int read(){
	int f=1,w=0,ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) w=(w<<3)+(w<<1)+(ch^48);
	return f*w;
}
#define pb push_back
#define all(x) ((x).begin(),(x).end())
#define sz(x) (int)(x.size()) 
const int N = 2e6 + 10, INF = 4e18;
int  n, d, a[N];
namespace Ds {
	const int N = 5010;
	int f[N][N], dist[N][N];
	void check(vector<int> p) {
		rep(i, 1, sz(p) - 1) {
			if (a[p[i]] - a[p[i - 1]] > d) return;
		}
		int s = p.front(), t = p.back();
		if (ckmin(dist[s][t], sz(p) - 1)) f[s][t] = 1;
		else if (dist[s][t] == sz(p) - 1) f[s][t]++;
	}
	void work() {
		rep(i, 1, n) rep(j, 1, n) dist[i][j] = INF, f[i][j] = 0;
		rep(i, 1, (1 << n) - 1) {
			vector<int> tmp;
			rep(j, 1, n) {
				if (i >> (j - 1) & 1) tmp.pb(j);
			}
			check(tmp);
		}
		int ans = 0;
		rep(i, 1, n) {
			rep(j, i + 1, n) {
				if (f[i][j] == 2) ans++;
			}
		}
		printf("%lld\n", ans);
	}
}
namespace As {
	void work() {
		int k = a[2] - a[1], sp = d / k;
		if (sp <= 1) {
			puts("0");
			return;
		}
		int ans = 0,j=sp+1;
		rep(i, 1, n) {
			while(j<sp+sp-1&&i-j>1) j++;
			if(i-j>=1) ans+=(j-sp+1)/2;
//			de(ans),bug(j);
		}
		printf("%lld\n", ans);
	}
}
int c, t;
signed main() {
//	freopen("migrate4.in", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	while (t--) {
		n = read(), d = read();
		rep(i, 1, n) {
			a[i] = read();
		}
		if(c==11||c==12) As::work();
		else Ds::work();
	}
	return 0;
}

