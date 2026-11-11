#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define MP make_pair
#define pb push_back
#define str string
#define db double
#define all(x) (x).begin(),(x).end()
#define ms(a,t) memset(a,t.sizeof(a))
const ll INF = 0x3f3f3f3f;
const ll mod = 998244353;
const int maxn = 5e5+10;
const int maxm = 5e5+10;
const db eps = 1e-6;
int n; ll m;
ll a[maxn];
ll s[maxn];
void Solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i++) {
		s[i] = s[i-1] + a[i];
	}
	int ans = 0;
	for(int i = 1,j = i; i <= n; i++) {
		while(j < i && a[i] * (i-j+1) > (s[i]-s[j-1])+m) {
			j++;
		}
		ans = max(ans,i-j+1);
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	int tt; cin >> tt; while(tt--)
	Solve();
	return 0;
}

