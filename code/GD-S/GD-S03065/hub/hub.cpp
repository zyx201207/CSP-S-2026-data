#include<iostream>
using namespace std;
using ll=long long;
#define pf printf
#define f(i,j,k) for(ll i=j;i<=k;i++)
#define F(i,j,k) for(ll i=j;i>=k;i--)
inline void R(ll&x){scanf("%lld",&x);}
ll c,t;
int main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	R(c),R(t);
	f(i,1,t){
		ll n,m;
		R(n),R(m);
		ll x=rand()%m;
		pf("%lld\n",x);
		f(j,1,n-1)R(n),R(m);
	}return 0;
}
