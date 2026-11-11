#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e6+5;
ll n,m,ans;
ll a[N];
ll f[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll d=a[2]-a[1];
	for(ll i=1;i<=n;i++) f[i]=d*(i-1)+f[i-1];
	for(int i=1;i<=n;i++){
		if(i!=n&&m>=f[i]&&m<f[i+1]) ans=i;
		else if (i==n&&m>=f[i]) ans=i;
	}
	printf("%lld\n",ans);	
//	for(ll i=1;i<=n;i++) printf("%lld ",f[i]);
}