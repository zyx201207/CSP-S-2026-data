#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXM = 5e5+5;
const int MAXN = 505;
const int MAXQ = 1e5+5;
ll c,n,m,d,q;
ll v[MAXN], k[MAXN];
ll a[MAXN][MAXM], t[MAXN][MAXM];
pair<ll, ll> r[MAXQ];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>v[i];
	for (int i=1;i<=n;i++) {
		cin>>k[i];
		for (int j=1;j<=k[i];j++) {
			cin>>a[i][j]>>t[a[i][j]][j];
		}
	}
	for (int i=1;i<=q;i++) {
		cin>>r[i].first>>r[i].second;
	}
	
	return 0;
}

