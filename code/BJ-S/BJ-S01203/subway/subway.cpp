#include<bits/stdc++.h>
using namespace std;
#define CO const
#define CC constexpr
#define CA CO auto
#define RE return
#define VE vector
#define PB push_back
#define FI first
#define SE second
#define TET template<class T>
using ll=long long;
using Ci=CO int;using Cl=CO ll;
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define FER(i,r,l) for(int i=(r);i>=(l);--i)
TET using pq=priority_queue<T,VE<T>,greater<>>;
TET CC void Max(T&x,T y){x=max(x,y);}
TET CC void Min(T&x,T y){x=min(x,y);}
CC int M=505,N=5e5+5;CC ll Mx=1e18;
int zq;
int n,m,T;
int a[N];
VE<pair<int,int>>v[N];
ll f[M][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>zq>>n>>m>>zq>>T;
	FOR(i,1,m)cin>>a[i];
	FOR(i,1,n){
		int k;cin>>k;
		while(k--){
			int x,y;cin>>x>>y;
			v[x].PB({i,y});
		}
	}
	FOR(i,1,n)FOR(j,1,n)f[i][j]=Mx*(i!=j);
	FOR(x,1,m)for(CA&i:v[x])for(CA&j:v[x])
		Min(f[i.FI][j.FI],(ll)i.SE+j.SE);
	FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)
		Min(f[i][j],f[i][k]+f[k][j]);
	while(T--){
		int x,y;cin>>x>>y;
		ll an=Mx;
		for(CA&i:v[x])for(CA&j:v[y])
			Min(an,f[i.FI][j.FI]+i.SE+j.SE);
		cout<<an+a[x]+a[y]<<'\n';
	}
	RE 0;
}