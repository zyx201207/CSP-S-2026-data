#include <bits/stdc++.h>
using namespace std;
void OI(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
void testOI(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate4.out","w",stdout);
}
typedef long long ll;
ll dist(ll x,ll y){
	return max(x-y,y-x);
}
const int N=2e6+5;
int C,T,n;
ll d,x[N],u;
void solve1(){
	for(;T--;){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		u=d/(x[2]-x[1]);
		ll ans=0;
		for(int i=1;i+u+1<=n;i++){
			ans++;
		}
		printf("%lld\n",ans);
	}
}
int main(){
//	OI();
OI();
	scanf("%d%d",&C,&T);
	solve1();
	return 0;
}
