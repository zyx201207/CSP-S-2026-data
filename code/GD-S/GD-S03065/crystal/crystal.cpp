#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
#define pf printf
#define f(i,j,k) for(ll i=j;i<=k;i++)
#define F(i,j,k) for(ll i=j;i>=k;i--)
inline void R(ll&x){scanf("%lld",&x);}
ll n,m,a[500010],s;
int main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	R(n),R(m);
	if(n>80000){
		f(i,1,n)R(a[i]);
		sort(a+1,a+n+1);
		ll k=a[2]-a[1],t=0,i=1;
		while(m>0)m-=k,t++;
		if(m<0)t--;
		for(;;i++){if(t<i)break;t-=i;}
		pf("%lld",t);
		return 0;
	}
	f(i,1,n)R(a[i]);
	sort(a+1,a+n+1);
	f(i,1,n){
		ll k=0;
		f(j,i+1,n){
			k+=(a[j]-a[j-1])*(j-i);
			if(k<=m)s=max(s,j-i+1);
			else break;
		}
	}pf("%lld",max(s,1ll));
	return 0;
}
