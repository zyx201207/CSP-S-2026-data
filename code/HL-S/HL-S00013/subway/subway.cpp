#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=(a); i<=(b); i++)
#define IloveCCF ios::sync_with_stdio(0);
#define Pleasegivememorepts cin.tie(0);
#define Thankyou cout.tie(0);
#define pb push_back
#define pli pair<long long, int>
#define vc vector
#define mp make_pair
typedef long long ll;
const int N=5e5+5;
const ll inf=0x3f3f3f3f3f3fLL;
struct Node{
	int v;
	ll w;
};
int c, n, m, d, q;
int w[N];
int a[N];
ll t[N];
vc<Node> G[N];
void dij(int s, int t){
	priority_queue<pli, vc<pli>, greater<pli> > q;
	vc<ll> dis(N, inf);
	q.push(mp(0, s));
	dis[s]=0;
	while (!q.empty()) {
		auto h=q.top();
		q.pop();
		int u=h.second;
		if (h.first>dis[u]) continue;
		for(auto it:G[u]){
			int v=it.v;
			ll w=it.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push(mp(dis[v], v));
			}
		}
	}
	cout << w[s]+w[t]+dis[t] << '\n';
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	IloveCCF
	Pleasegivememorepts
	Thankyou
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m)
		cin >> w[i];
	rep(i, 1, n){
		int k;
		cin >> k;
		rep(i, 1, k)
			cin >> a[i] >> t[i];
		rep(i, 1, k) rep(j, i+1, k){
			G[a[i]].pb(Node{a[j], t[i]+t[j]});
			G[a[j]].pb(Node{a[i], t[i]+t[j]});
		}
	}
	while (q--) {
		int s, t;
		cin >> s >> t;
		dij(s, t);
	}
	return 0;
}