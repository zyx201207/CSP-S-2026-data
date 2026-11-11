#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define MP make_pair
#define pb push_back
#define pii pair<int,int> 
#define pll pair<ll,ll> 
#define str string
#define db double
#define all(x) (x).begin(),(x).end()
#define ms(a,t) memset(a,t.sizeof(a))
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
const int maxn = 5e5+10;
const int maxm = 500+10;
const db eps = 1e-6;
int c,n,m,d,q;
int w[maxn];
ll a[maxm][maxm];
int len[maxn];
vector<pii > st[maxn];
//vector<int> vec[maxm],dis[maxm]; 
void Solve() {
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> len[i]; 
		for(int j = 0; j < len[i]; j++) {
			int x,y;
			cin >> x >> y;
			st[x].pb(MP(i,y));
		} 
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			a[i][j] = INF;
		}
		a[i][i] = 0; 
	}
	for(int i = 1; i <= m; i++) {
		for(pii u : st[i]) {
			for(pii v : st[i]) {
				a[u.fi][v.fi] = min(a[u.fi][v.fi],(ll)u.se+(ll)v.se);
			}
		}
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
			}
		} 
	}
	for(int i = 1; i <= q; i++) {
		int x,y;
		ll ans = INF;
		cin >> x >> y;
		for(pii u : st[x]) {
			for(pii v : st[y]) {
				ans = min(ans,a[u.fi][v.fi]+u.se+v.se+w[x]+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	int tt; cin >> tt; while(tt--)
	Solve();
	return 0;
}

