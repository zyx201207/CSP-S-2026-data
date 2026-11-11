#include<bits/stdc++.h>
#define ll long long
#define il inline
#define pll pair<ll, ll> 
using namespace std;

il ll read(){
	ll res = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f *= -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		res = (res<<3) + (res<<1) + (ch^48);
		ch = getchar();
	}
	return res;
}

bool stMST;
ll c,n,m,d,q, w[500100];
vector<pll> id[500100];
ll g[510][510];

bool edMST;

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

//	cout<<abs(&edMST-&stMST) / 1024.0 / 1024 <<" MB\n";
	
	c = read(), n = read(), m = read(), d = read(), q = read();
//	cout<<"###"<<c<<' '<<n<<' '<<m<<' '<<d<<' '<<q<<'\n';
	
	for(int i=1;i<=m;++i){
		w[i] = read();
//		cout<<"##"<<w[i]<<'\n';
	}
	
	for(ll len,i=1;i<=n;++i){
		len = read();
		for(ll a,t,j=1;j<=len;++j){
			a = read(), t = read();
			id[a].push_back({i, t});
//			cout<<"#"<<i<<' '<<a<<' '<<t<<'\n';
		}
	}
	
	memset(g, 0x3f, sizeof(g));
	
	for(int i=1;i<=m;++i){
		for(auto j : id[i]){
			ll u = j.first, uw = j.second;
			for(auto k : id[i]){
				if(j == k) continue;
				ll v = k.first, vw = k.second;
//				cout<<"$"<<u<<' '<<v<<' '<<uw+vw<<'\n';
				g[u][v] = min(g[u][v], uw+vw);
			}
		}
	}
	
	for(int i=1;i<=n;++i) g[i][i] = 0;
	
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	
	
	for(ll x,y,ans,i=1;i<=q;++i){
		cin>>x>>y;
		ans = 4e18;
		for(auto j : id[x]){
			ll u = j.first, uw = j.second;
			for(auto k : id[y]){
				ll v = k.first, vw = k.second;
//				cout<<u<<' '<<v<<' '<<g[u][v]+uw+vw<<'\n';
				ans = min(ans, g[u][v]+uw+vw);
			}
		}
		cout<<ans + w[x]+w[y]<<'\n';
	}
	
	
	return 0;
} 
