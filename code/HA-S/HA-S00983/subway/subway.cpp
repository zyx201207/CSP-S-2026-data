#include<bits/stdc++.h>
#define ll long long
#define N 600100

using namespace std;

int n,c,T,d;
ll m,a[N],b[N][4],maxx,f[N][4];
vector<pair<ll,ll >> dd[N],e[N];

inline void ff(ll s,ll t) {
	memset(b,0,sizeof b);
	memset(f,0x3f,sizeof f);
	priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> q;
	q.push({0,{s,0}});
	f[s][0]=0;
	while(!q.empty()) {
		auto ww=q.top();
		q.pop();
		ll id=ww.first,u=ww.second.first,w=ww.second.second;
		if(b[u][id]) {
			continue;
		}
		b[u][id]=1;
		if(id==0) {
			f[u][1]=min(f[u][1],w+a[u]);
			q.push({1,{u,w+a[u]}});
		}
		else if(id==1) {
			f[u][0]=min(w+a[u],f[u][0]);
			q.push({0,{u,w+a[u]}});
			for(auto v : e[u]) {
				ll idd=v.first,vv=v.second;
				if(f[idd][2]>w+vv) {
					f[idd][2]=w+vv;
					q.push({2,{idd,w+vv}});	
				}
			} 
		}
		else {
			for(auto v : dd[u]) {
				ll idd=v.first,vv=v.second;
				if(f[idd][1]>w+vv) {
					f[idd][1]=w+vv;
					q.push({1,{idd,w+vv}});	
				}
			} 			
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> T;
	for(int i = 1; i <= m; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i) {
		ll k;
		cin >> k;
		for(int j = 1; j <= k; ++j) {
			ll x,y;
			cin >> x >> y;
			dd[i].push_back({x,y});
			e[x].push_back({i,y});
		}
	}
	while(T--) {
		ll s,t;
		cin >> s >> t;
		ff(s,t);
		cout << f[t][0] << "\n";
	}
	return 0;
} 
