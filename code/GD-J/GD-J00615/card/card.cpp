#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5,M=3e5+5;
ll n,m;
ll a[N],b[N];
ll cnt[M]={0},is[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=0;
		for(ll j = i-1;i>=1;j--){
			if(a[i]==a[j]){
				b[i]=j;
				break;
			}
		}
	}
	for(ll i = 1;i<=n;i++){
		memset(is,0x3f,sizeof(is));
		for(ll j=i;j<=n;j++){
			if(b[j]>=i&&is[b[j]]){
				for(ll k = b[j];k<j;k++){
					is[k]=0;
				}
			}
		}
		for(ll j=i;j<=n;j++){
			if(is[j]) cnt[a[j]]++;
		}
	}
	for(ll i = 1;i<=m;i++) printf("%lld ",cnt[i]);
	return 0;
}
