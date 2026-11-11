#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005],a1[100005],cnt[100005];
int main(){
	freopen("card1.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		a1[i]=a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(a1[i]==a[j]){
				cnt[j]++;
				for(ll k=j;k<=n;k++){
					a1[j]=0;
				}
			}
		}
	}  
	for(ll i=1;i<=m;i++){
		cout<<cnt[i];
	}
	return 0;
}

