#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,m,maxa=1;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		ll ans=0;
		//a[i]是当前选定的能量值 
		ll cnt=1;
		for(ll j=i-1;j>=1;j--){
			ll mk=a[i]-a[j];//差值
			if(a[j]==a[i]){
				cnt++;
				continue;
			}
			if(ans+mk>m){
				break;
			}else{
				//printf("!ans %d ",ans);
				ans+=mk;
				cnt++;
				maxa=max(maxa,cnt);
			}
		}
		//printf("!cnt %d\n",cnt);
	}
	printf("%lld",maxa);
	return 0;
} 
