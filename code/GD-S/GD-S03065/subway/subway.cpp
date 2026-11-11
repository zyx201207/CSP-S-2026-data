#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
using ll=int;
#define pf printf
#define f(i,j,k) for(ll i=j;i<=k;i++)
#define F(i,j,k) for(ll i=j;i>=k;i--)
#define pb push_back
#define st first
#define nd second
inline void R(ll&x){scanf("%d",&x);}
ll c,n,m,d,q,w[500010],k[500010],s;
vector<pair<ll,ll>>v[500010];
int main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	R(c),R(n),R(m),R(d),R(q);
	f(i,1,m)R(w[i]);
	f(i,1,n){
		R(k[i]);
		f(j,1,k[i]){
			ll a,b;
			R(a),R(b),v[a].pb({i,b});
		}
	}f(i,1,q){
		ll a,b,s=0;
		R(a),R(b),s=w[a]+w[b];
		for(auto x:v[a])for(auto y:v[b])if(x.st==y.st){pf("%lld\n",s+x.nd+y.nd);goto G;}
		cout<<n*m<<'\n';
		G:;
	}
	return 0;
}
