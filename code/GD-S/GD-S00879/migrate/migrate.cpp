#include <bits/stdc++.h>
#define up(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define dn(a,b,c) for(int (a)=(b);(a)>=(c);(a)--)
#define fst first
#define sed second
#define pref static inline
using namespace std;
using ll=long long;using pii=pair<int,int>;using pll=pair<ll,ll>;using vi=vector<int>;
using vl=vector<ll>;using vpi=vector<pii>;using vpl=vector<pll>;using pil=pair<int,ll>;
using vpil=vector<pil>;
namespace my{
	const int N=5005,inf=1e9;
	int n;
	pii f[N][N];
	ll d,x[N];
	pref pii chk(pii x,pii y){
		if(x.fst==y.fst)return {x.fst,x.sed+y.sed};
		else if(x.fst<y.fst)return x;
		return y;
	}
	void SOLVE(){
		cin>>n>>d;
		up(i,1,n)cin>>x[i];
		up(i,1,n)up(j,i,n)f[i][j]={inf,0};
		ll ans=0;
		up(r,1,n){
			f[r][r]={0,1};
			dn(l,r,1){
//				if(f[l][r].sed>=3)break;
				if(f[l][r].sed==2)ans++;
				int idx=l-1;
//				cout<<l<<' '<<r<<' '<<f[l][r].fst<<' '<<f[l][r].sed<<'\n'; 
				while(x[l]-x[idx]<=d&&idx>=1)
					f[idx][r]=chk(f[idx][r],(pii){f[l][r].fst+1,f[l][r].sed}),idx--;
			}
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int _=1,test;cin>>test>>_;
	while(_--)my::SOLVE();
	return 0;
}

