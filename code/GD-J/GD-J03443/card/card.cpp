#include<iostream>
#include<vector>
using namespace std;
using ll=long long;
#define pf printf
#define f(i,j,k) for(ll i=j;i<=k;i++)
#define F(i,j,k) for(ll i=j;i>=k;i--)
#define pb push_back
inline void R(ll&x){scanf("%lld",&x);}
ll n,m,a[500010],c[300010];
vector<ll>v;
int main(){
	freopen("card.in","r",stdin),freopen("card.out","w",stdout);
	R(n),R(m);
	f(i,1,n)R(a[i]);
	f(i,1,n){
		f(j,i,n){
			ll t=-1;
			for(auto x:v){
				t++;
				if(x==a[j])break;
			}ll sz=v.size()-t;
			if(v.size()&&v[t]==a[j])f(k,1,sz)v.pop_back();
			v.pb(a[j]);
		}for(auto a:v)c[a]++;
		v.clear();
	}f(i,1,m)pf("%lld ",c[i]);
	return 0;
}