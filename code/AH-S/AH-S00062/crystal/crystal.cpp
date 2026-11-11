#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m,a[N],ans=0,maxn=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%lld",a+i);
	if(n<=5000){
		sort(a+1,a+n+1);
		for(ll base=2;base<=n;base++){
			ll tmp=m;ans=1;
			for(ll i=1;i<base;i++){
				tmp-=abs(a[base]-a[i]);
				if(tmp>=0)ans++;
				else break;
			}
			maxn=max(maxn,ans);
		}
		printf("%lld",maxn);
		return 0;
	}
	ll a1=a[1],T=a[2]-a[1];
	ans=floor(   (1.0*(T-2*a1)+sqrt(  (2*a1-T)*(2*a1-T) + 8*m*T ))/T/2  ) +1;
	printf("%lld",ans);
	return 0;
}
// 10 min +15 min +25 min EXP:45pts+15pts(A)+15pts(B)=75pts
