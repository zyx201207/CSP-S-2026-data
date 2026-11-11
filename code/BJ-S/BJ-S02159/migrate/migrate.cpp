#include <bits/stdc++.h>
using namespace std;
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
#define pre(i,n) for(int i = n;i;--i)
#define rep(i,n) for(int i = 1;i <= n;++i)
#define rpt(i,a,n) for(int i = a;i <= n;++i)
#define repg(i,u) for(int i = head[u];i;i = e[i].nxt)
#define WR(x) cerr<<#x<<':'<<x<<endl
#define int long long
#define swap(x,y) (x ^= y ^= x ^= y)
constexpr int N = 2e6 + 5,inf = 4e18;
int c,T,n,d;
namespace sub1{
	int dis[N],x[N],cnt[N],mx[N],res;
	inline bool chk(int i,int j){ return x[j] - x[i] <= d; }
	inline int cal(int s){
		rpt(i,s + 1,n) dis[i] = inf;
		dis[s] = 0;
		int l = s,r = n;
		rpt(i,0,n) mx[i] = -1;
		rpt(i,s,n){
			if(dis[i] > n){
				r = i - 1;
				break;
			}
			while(l < n && chk(i,l + 1)) ++l,dis[l] = dis[i] + 1;
			mx[dis[i]] = i;
		}
		int res = 0;
		rep(i,n) cnt[i] = inf;
		cnt[s] = 1;
		rpt(i,s + 1,r){
			int fa = mx[dis[i]-1];
			if(cnt[fa] <= 2 && cnt[fa]){
				if(cnt[fa] == 2){
					if(fa == s || !chk(fa - 1,i)) cnt[i] = 2;
				}
				else {
					if(fa ^ s && chk(fa - 1,i) && cnt[fa-1] == 1 && (fa - 1 == s || !chk(fa - 2,i))) cnt[i] = 2;
					else if(fa == s || !chk(fa - 1,i)) cnt[i] = 1;
				}
				res += (cnt[i] == 2);
			}
		}
		// cerr<<s<<' '<<res<<endl;
		return res;
	}
	inline void solve(){
		cin>>n>>d,res = 0;
		rep(i,n) cin>>x[i];
		rep(i,n) res += cal(i);
		cout<<res<<'\n';
	}
	inline void Main(){ while(T--) solve(); }
}
namespace sub11{
	int x[N],d2;
	inline void solve(){
		cin>>n>>d;
		rep(i,n) cin>>x[i];
		if(n == 1) return cout<<"0\n",void();
		d2 = x[2] - x[1];
		int cnt = d / d2;
		if(cnt <= 1) return cout<<"0\n",void();
		//i + cnt + cnt - 1 <= n.i+cnt*2-1<=n.i<=n+1-2*cnt
		cout<<max(0ll,n + 1 - 2 * cnt)<<'\n';
	}
	inline void Main(){ while(T--) solve(); }
}
namespace sub13{
	int a[N],x,res;
	inline bool chk(int i,int j){ return a[j] - a[i] <= d; }
	inline void solve(){
		cin>>n>>d,res = 0;
		rep(i,n) cin>>a[i];
		rep(i,n) if(chk(1,i) && chk(i,n)) x = i;
		int cnt1 = 0,cnt2 = 0;
		if(x ^ 1) rpt(i,x + 1,n) cnt1 += !chk(x - 1,i);
		else cnt1 = n - x;
		if(x > 2) rpt(i,x + 1,n) cnt2 += !chk(x - 2,i);
		else cnt2 = n - x;
		rep(u,x - 1){//v > x
			if(x ^ n && chk(u,x + 1)){//x-1不到v,u不到x+2,u到x+1
				if(x + 2 <= n && chk(u,x + 2)) continue;
				//x-1不到v. u = x - 1也不行
				res += cnt1;
			}
			else {//u到x-1,x-2不到v,u不到x+1
				if(u == x - 1) continue;
				//x-2不到v
				res += cnt2;
			}
		}
		cout<<res<<'\n';
	}
	inline void Main(){ while(T--) solve(); }
}
signed main(){
	// fin("migrate4.in"),fout("migrate.out");
	fin("migrate.in"),fout("migrate.out");
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	if(c <= 10) sub1::Main();
	else if(c <= 12) sub11::Main();
	else if(c <= 14) sub13::Main();
	cerr<<'\n'<<1.0 * clock() / CLOCKS_PER_SEC;
	return 0;
}