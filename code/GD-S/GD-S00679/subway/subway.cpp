#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define int long long
#define pii std::pair<int,int>
#define rep(x,qwq,qaq) for(int (x)=(qwq);(x)<=(qaq);++(x))
#define per(x,qwq,qaq) for(int (x)=(qwq);(x)>=(qaq);--(x))
#define pb push_back
#define fi first
#define se second
const int N=1e5+7,M=505;
const ll inf=1e18;
int n,m,d,q,w[N],k[N],v[M],dt[M][M];
std::vector<pii> g[M],a[M],t[M];
std::vector<int> lxl[N];
void sr(){
	std::cin>>n>>m>>d>>q;
	rep(i,1,m) std::cin>>w[i];
	rep(i,1,n){
		std::cin>>k[i];
		rep(j,1,k[i]){
			int x,y;
			std::cin>>x>>y;
			a[i].pb({j,x});
			t[i].pb({j,y});
		} 
	}
}
int ft(int i,int j){
	if(i==j) return 0;
	ll cnt=inf;
	for(int p=0;p<a[i].size();p++){
		int tt=a[i][p].se;
		v[tt]=t[i][p].se;
	}
	for(int p=0;p<a[j].size();p++){
		int tt=a[j][p].se;
		if(v[tt]!=-inf){
			cnt=v[tt]+t[j][p].se;
		}
	}
	for(int p=0;p<a[i].size();p++){
		int tt=a[i][p].se;
		v[tt]=t[i][p].se;
	}
	return cnt;
}
void f(){
	rep(i,1,n){
		rep(j,1,n){
			dt[i][j]=ft(i,j);
		}
	}
}
ll qry(int x,int i){
//	std::cout<<x<<' '<<i<<' '<<a[i].size()<<'\n';
	for(int j=0;j<a[i].size();j++){
		auto tp=a[i][j];
//		std::cout<<tp.fi<<' '<<tp.se<<'\n';
		if(tp.se==x) return t[i][j].se;
	}
	return inf;
}
void solve(){
	rep(i,1,n){
		for(int j=0;j<a[i].size();j++){
			lxl[a[i][j].se].pb(i);
		}
	}
	f();
//	rep(i,1,n){
//		rep(j,1,n){
//			std::cout<<dt[i][j]<<" \n"[j==n];
//		}
//	}
//	rep(i,1,m){
//		for(auto x:lxl[i]) std::cout<<x<<' ';
//		std::cout<<'\n';
//	}
	ll ans=inf;
	while(q--){
		int l,r;
		std::cin>>l>>r;
		ans=inf;
		for(auto x:lxl[l]){
			for(auto y:lxl[r]){
				if(dt[x][y]==inf) continue;
				ll res=dt[x][y]+qry(l,x)+qry(r,y);
//				std::cout<<x<<' '<<y<<'\n';
//				std::cout<<dt[x][y]<<' '<<qry(l,x)<<' '<<qry(r,y)<<'\n';
				ans=std::min(ans,res);
			}
		}
		std::cout<<ans+w[l]+w[r]<<'\n';
	}
} 
signed main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	int T=1,c;
//	std::cin>>T;
	std::cin>>c;
	sr();
	solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
