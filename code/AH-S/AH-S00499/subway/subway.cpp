#include <bits/stdc++.h>
#define ll long long
#define up(i,a,b) for (int i=(a);i<=(b);i++)
#define down(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
const int N=505,M=5e5+5;
const ll inf=1e15;
int c,n,m,d,q;
ll w[M],f[N][N];//f[i][j]:从i号线到j号线用时
struct data{int id;ll t;};
vector<data> dot[N];
vector<data> g[M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	up(i,1,m) cin>>w[i];
	up(i,1,n) up(j,1,n) f[i][j]=(i==j?0:inf);
	up(i,1,n){
		int k;cin>>k;
		up(j,1,k){
			int x;ll y;cin>>x>>y;
			dot[i].emplace_back((data){x,y});
			g[x].emplace_back((data){i,y});
		}
	}
	up(i,1,n) for (data k1:dot[i]){
		int x=k1.id;ll t1=k1.t;
		for (data k2:g[x]){//O(Md)
			int j=k2.id;ll t2=k2.t;
			f[i][j]=min(f[i][j],t1+t2);
		}
	}
//	up(i,1,n){
//		up(j,1,n) cout<<f[i][j]<<' ';
//		cout<<'\n';
//	}
	up(mid,1,n) up(i,1,n) up(j,1,n) f[i][j]=min(f[i][j],f[i][mid]+f[mid][j]);//O(n^3)
	up(i,1,q){
		int x,y;cin>>x>>y;
		ll ans=inf;
		for (data k1:g[x]) for (data k2:g[y]){//O(d^2*q)
			ans=min(ans,f[k1.id][k2.id]+k1.t+k2.t);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
