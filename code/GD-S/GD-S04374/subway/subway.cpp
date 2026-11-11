#include<bits/stdc++.h>
using namespace std;
using ll=long long; 
using pii=pair<int,int>;
#define _for(i,a,b) for(int i=a,IM=b;i<=IM;i++)

const int N=5e5+9;
int w[N];
vector<pii> ve[N];
/*
对于路线的切换是从一个站点到站台再到站点 
对于不同的路线可以进行染色，在路线的交点可以进行切换 
但每一个站点所对应的颜色的切换代价是不同的 
也就是说从每个站点切换颜色代价是不同的 
*/ 
void solve () {
	int c,n,m,d,q; cin>>c>>n>>m>>d>>q;
	_for(i,1,m) cin>>w[i];
	_for(i,1,n) {
		int k; cin>>k;
		_for(i,1,k) {
			int x,w; cin>>x,w;
			ve[i].push_back({x,w});
		}
	}
	while(q--) {
		int s,e; cin>>s>>e;
		ll ans=w[s]+w[e];
		_for(i,1,n) {
			for(pii pi:ve[i]) if(pi.first==s) 
		}
	}
}
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	return 0;
}
/*
5 5
1 2 4 8 9
*/
