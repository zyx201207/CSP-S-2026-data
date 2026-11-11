#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[501111],cnt[301111];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=n;i++){
		ll b[501111]={0},pos=0;
		for(ll j=i;j<=n;j++){
			pos++;
			b[pos]=a[j];
	        for(ll k=1;k<=pos;k++){
				if(b[k]==a[j]){
					ll x=pos;
					pos-=(x-k);
					break;
				}
			}
		}
		ll t[301111]={0};
		for(ll j=1;j<=pos;j++){
			t[b[j]]++;
		}
		for(ll j=1;j<=m;j++){
			if(t[j]==1){
				cnt[j]++;
			}
		}
	}
	for(ll i=1;i<=m;i++){
		printf("%lld ",cnt[i]);
	}
	return 0;
}
