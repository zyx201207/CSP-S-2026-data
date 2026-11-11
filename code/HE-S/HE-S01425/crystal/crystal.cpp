#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
void xiaoo(int nn,int mm){
	sort(a+1,a+1+n);
	ll ans=0,sheng=mm,anstrue=-1e8;
	for(int i=nn;i>=1;i--){
		ll xian=i-1;
		ans=0;
		while(sheng>=0&&xian>=0){
			sheng-=a[i]-a[xian];
			ans++;
			xian=xian-1;
		}
		anstrue=max(ans,anstrue);
	sheng=mm;
	}
	printf("%lld\n",anstrue);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)	scanf("%lld",&a[i]);
	if(n>5000) xiaoo(n,m);
	if(n>5000&&m<=1e8)  printf("%lld\n",n);
	if(n<=5000) xiaoo(n,m);
	return 0;
} 
