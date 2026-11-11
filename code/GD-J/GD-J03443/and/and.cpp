#include<iostream>
#include<string>
using namespace std;
using ll=long long;
#define pf printf
#define f(i,j,k) for(ll i=j;i<=k;i++)
#define F(i,j,k) for(ll i=j;i>=k;i--)
inline void R(ll&x){scanf("%lld",&x);}
ll n,m,a[200010],mx;
void D(ll x,ll t,ll k){
	if(x==m){mx=max(mx,k);return;}
	f(i,t+1,n)D(x+1,i,k&a[i]);
}int main(){
	freopen("and.in","r",stdin),freopen("and.out","w",stdout);
	R(n),R(m);
	f(i,1,n)R(a[i]);
	f(i,1,n)D(1,i,a[i]);
	pf("%lld",mx);
	return 0;
}