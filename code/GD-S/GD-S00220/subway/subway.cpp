#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

typedef long long  ll;
ll c,n,m,d,q;
//int w[(int)5e5+5];
bool vis[(int)5e5+5];
ll k[505];//ÏßÂ·Õ¾Êý
int a[505][(int)5e5+5];
//int t[505][(int)5e5+5];
//pair<int,int> rt[(int)1e5];

struct node {
	ll idx,w;
	map<ll,ll> chg;
	set<ll> line;
	vector<ll> nxt;
};

map <ll,node>stt;

ll dfs(ll x, ll y, ll l) {
//	cerr << "vis "<<x <<"" << endl;
	vis[x] = 1;
	if(x == y) {
		vis[x]=0;
		return (stt[x].chg[l] + stt[x].w);
	}
	ll mind = 0x3f3f3f3f3f3f3f3f;
	for(int i=0; i<stt[x].nxt.size(); i++) {
		if(vis[stt[x].nxt[i]])continue;
		for(auto j:stt[stt[x].nxt[i]].line) {
			if(j == l) {
				mind = min(mind, dfs(stt[x].nxt[i], y, l));
			} else {
				bool f = (stt[x].chg.find(j) != stt[x].chg.end());
//				cerr << "can interchange with " << j << "?: " << f << endl;
				if(!f){
//					cerr << "At " << x << "; try to go " << stt[x].nxt[i] << " with "<<j << endl;
					;
				}
				if(f)mind = min(mind, dfs(stt[x].nxt[i], y, j) + stt[x].chg[l] + stt[x].chg[j]);
			}
		}
	}
	vis[x]=0;
	return mind;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin >> c >> n >> m >> d >> q;

	for(ll i=1; i<=m; i++) {
		ll t;
		cin >> t;
		stt[i].w = t;
	}

	for(ll i=1; i<=n; i++) {
		cin >> k[i];
		for(int j=1; j<=k[i]; j++) {
			cin >> a[i][j] >> stt[a[i][j]].chg[i];
		}
	}

	for(ll i=1; i<=n; i++) {
		for(ll j=1; j<=k[i]; j++) {
			stt[a[i][j]].line.insert(i);
			if(j>1)stt[a[i][j]].nxt.push_back(a[i][j-1]);
			if(j<k[i])stt[a[i][j]].nxt.push_back(a[i][j+1]);
		}
	}

	for(ll r=1; r<=q; r++) {
		ll x,y;
		cin >> x >> y;
		ll res = 0x3f3f3f3f3f3f3f3f;
		for(ll i:stt[x].line) {
			res = min(res, dfs(x,y,i) + stt[x].w + stt[x].chg[i]);
		}
		cout << res << endl;
	}

	return 0;
}
