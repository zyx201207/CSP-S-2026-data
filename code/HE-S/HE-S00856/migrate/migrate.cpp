#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d,nxt[2000010],cc[2000010],ff[2000010],x[2000010];
int o = 0; void solve() {
	//cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> x[i],cc[i] = ff[i] = 1;
	//o++; if(o != 14) return ;
	int sp = 0,p = 1; for(int i = 1; i <= n; i++) {
		while(p < n && x[p+1]-x[i] <= d) p++; nxt[i] = p;
	}
	p = 1; for(int i = 1; i <= n; i++) {
		while(p < n && x[i]-x[p] > d) p++;
		if(p < i) {
			if(nxt[p] == i && nxt[i-1] < nxt[i]-1) ff[i] += ff[p];
		}
	}
	p = n; for(int i = n; i >= 1; i--) {
		while(p > 1 && x[i]-x[p-1] <= d) p--;
		if(i < nxt[i]-1) {
			int w = 0;
			if(nxt[nxt[i]-1] > nxt[i]) w = cc[nxt[i]-1]-1;
			//cout << i << ' ' << ff[i] << ' ' << w << endl;
			sp += ff[i]*w;
		}
		//cout << i << ' ' << sp << ' ' << cc[i] << endl;
		if(p < i) {
			if(nxt[p] == i) cc[p] += cc[i];
			else cc[p]++;
		}
	} printf("%lld\n",sp);
}
namespace sml {
	int dis[5005],way[5005],ss[5005];
	void solve() {
		//cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		int sp = 0; for(int r = n; r >= 1; r--) {
			int ll = r,rr = r; ss[r+1] = 0;
			dis[r] = 0,way[r] = ss[r] = 1;
			for(int l = r-1; l >= 1; l--) {
				while(rr > l && x[rr]-x[l] > d) rr--;
				while(ll > l+1 && dis[ll-1] <= dis[rr]) ll--;
				if(rr == l) break;
				dis[l] = dis[rr]+1; way[l] = min(ss[ll]-ss[rr+1],3ll);
				//cout << l << ' ' << r << ' ' << dis[l] << ' ' << way[l] << ' ' << ll << ' ' << rr << endl;
				ss[l] = ss[l+1]+way[l];
				if(way[l] == 2) sp++;
			}
		} printf("%lld\n",sp);
	}
}
signed main() {
	freopen("migrate.in","r",stdin); freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int c,T; cin >> c >> T; while(T--) {
		cin >> n >> d;
		if(n <= 5000) sml::solve(); else solve();
	}
	return 0;
}
