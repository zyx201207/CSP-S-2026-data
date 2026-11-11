#include<bits/stdc++.h>
#define ll int
using namespace std;
ll n,k;
ll a[500005];
ll m[5005][5005];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(m[i][a[j]]==1){
				for(ll k=j-1;k>=1;k--){
					if(a[j]==a[k]) break;
					m[i][a[k]]=0;
				}
			}
			m[i][a[j]]=1;
		}
		ll sum=0;
		for(ll j=1;j<=n;j++){
			if(m[j][i]==i) sum++;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
