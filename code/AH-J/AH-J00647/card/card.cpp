#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
ll t[500005];
ll wz[500005];
ll cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(t[a[j]]==0){
				t[a[j]]=1;
				wz[a[j]]=j;
			}else{
				for(ll k=wz[a[j]];k<j;k++){
				t[a[k]]=0;	
				}
			}
		}
		for(ll j=1;j<=m;j++){
			if(t[j]==1){
				cnt[j]++;
			}
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
