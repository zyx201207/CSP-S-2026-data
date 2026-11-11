#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define Rep(i,j,k) for(int i=j;i>=k;--i)
#define L(i,j,k) for(int i=j;i<k;++i)
using namespace std;
using ll = long long;
const int N = 1e6+10;
ll n, m, a[N], s[N];
void ckmax(int &x,int y){
	x = max(x, y); return;
}
int ck(int l,int r,ll v){
	ll len = r - l + 1, nd = 1ll * len * v - (s[r] - s[l - 1]); return (nd <= m);
}
void solve(){
	cin >> n >> m; int res = 0;
	rep(i,1,n) cin >> a[i]; sort(a+1,a+1+n);
	rep(i,1,n) s[i] = s[i - 1] + a[i];
	rep(i,1,n){
		int l = 1, r = i; int val = 0;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(ck(i - mid + 1, i, a[i])) val = mid, l = mid + 1;
			else r = mid - 1;
		}
		ckmax(res, val);
	}
	cout << res << "\n"; return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; // cin >> T;
	while(T--){
		solve();
	}
	return 0;
} 


