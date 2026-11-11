#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define Rep(i,j,k) for(int i=j;i>=k;--i)
#define L(i,j,k) for(int i=j;i<k;++i)
#define mem(x,v) memset(x,v,sizeof x)
#define Sz(s) (s).size()
#define fi first
#define se second
#define pb push_back
using namespace std;
#define int long long
using ll = long long;
const int N = 2e6+10;
const ll INF = 1e16;
using vi = vector<int>;
using pii = pair<int,int>;
void ckmin(ll &x,ll y){
	x = min(x, y); return;
}
int n; ll d, x[N], dis[N], ct[N];
void calc(int u){
	Rep(v,n,u+1){
		if(x[v] - x[u] <= d){
			if(dis[v] > dis[u] + 1){
				dis[v] = dis[u] + 1, ct[v] = 1; calc(v);
			}
			else if(dis[v] == dis[u] + 1) ct[v]++;
		}
	}
	return;
}
void solve(){
	cin >> n >> d; ll res = 0;
	rep(i,1,n) cin >> x[i];
	rep(i,1,n){
		rep(j,i+1,n) dis[j] = INF; calc(i);		
		rep(j,i+1,n){
			if(dis[j] < INF && ct[j] == 2) ++res;
		}
	}
	cout << res << "\n";
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, T = 1; cin >> c >> T;
	while(T--){
		solve();
	}
	return 0;
} 

