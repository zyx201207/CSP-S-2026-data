#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair
#define pb push_back
#define str string
#define db double
#define all(x) (x).begin(),(x).end()
#define ms(a,t) memset(a,t.sizeof(a))
const ll INF = 0x3f3f3f3f;
const ll mod = 998244353;
const int maxn = 2e6+10;
const int maxm = 2e5+10;
const db eps = 1e-6;
int n;
ll d;
ll a[maxn];
ll nxt[maxn];
ll f[maxn][3];
void Solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1,j = 1; i <= n; i++) {
		while(j < n && a[j+1]-a[i] <= d) j++;
		nxt[i] = j;
	}
	for(int i = 1; i <= n; i++) {
		f[i][0] = f[i][1] = f[i][2] = 0;
	}
	ll ans = 0;
	for(ll i = n; i >= 1; i--) if(nxt[i] != i) {
		if(nxt[i-1] < nxt[i]) {
			f[i][0] += f[nxt[i]][0];
			f[i][2] += f[nxt[i]][2];
		}
		if(nxt[i-1] < nxt[i]-1) {
			f[i][2] += f[nxt[i]][1];
		} 
		f[i][0] += nxt[i]-nxt[i-1];
		if(i >= 2 && nxt[i] == nxt[i-1] && nxt[i-2] < nxt[i]) {
			f[i][1] += f[nxt[i]][0];
		}
		if(i >= 2 && max(i,nxt[i-2]) < nxt[i-1]) {
			f[i][1] += nxt[i-1]-max(i,nxt[i-2]);
		}
		ans += f[nxt[i]][2]+f[nxt[i]][1];
//		cerr<<i<<' '<<nxt[i]<<' '<<f[i][0]<<' '<<f[i][1]<<' '<<f[i][2]<<' '<<ans<<'\n';
	}
	cout<<ans<<'\n';
//	cerr<<n<<'\n';
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int cc,tt; cin >> cc >> tt; while(tt--)
	Solve();
	return 0;
}

