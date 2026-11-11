#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
ll a[500005];
ll b[500005];
ll c[500005];


int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=m;i++){
		ll ans=0;
		for(ll j=1;j<=n;j++){
			memset(b,0,sizeof(b));
			ll cnt=0;
			for(ll k=j;k<=n;k++){
				if(b[a[k]]==0){
					cnt++;
					c[cnt]=a[k];
					b[a[k]]=1;
				}
				else{
					while(c[cnt]!=a[k]){
						b[c[cnt]]=0;
						c[cnt]=0;
						cnt--;
					}
				}
			}
			ll yes=0;
			for(ll k=1;k<=cnt;k++){
				if(c[k]==i){
					yes=1;
					break;
				}
			}
			if(yes==1)ans++;
		}
		cout<<ans<<' ';
	}
	
	return 0;
}


