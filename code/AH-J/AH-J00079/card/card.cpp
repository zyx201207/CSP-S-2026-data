#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],cnt[300010],t[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=n;i++){
		ll r=1;
		for(ll j=i;j<=n;j++){
			ll k=a[j];
			ll flag=-1;
			for(ll p=1;p<r;p++){
				if(t[p]==k){
					flag=p;
					break;
				} 
			}
			if(flag!=-1) r=flag;
			t[r]=a[j];
			r++;
		}
		for(ll j=1;j<r;j++){
			cnt[t[j]]++;
		}
	}
	for(ll i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
