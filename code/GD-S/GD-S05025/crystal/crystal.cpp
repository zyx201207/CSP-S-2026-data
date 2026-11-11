#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005]={0},w[5005][5005]={0},n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5005){
		for(ll i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				w[i][j]=a[j]-a[i];
			}
		}
		ll ans=0;
		for(ll i=n;i>=1;i--){
			ll t=m,s=0;
			for(ll j=i-1;j>=1;j--){
				if(t>=w[j][i]){
					t-=w[j][i];
					s++;
				}
				else{
					break;
				}
			}
			ans=max(ans,s+1);
		}
		cout<<ans;
	}
	else{
		for(ll i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		ll d=a[2]-a[1];
		if(d==0) cout<<n;
		else {
			ll S=sqrt(2*m/d);
			while(S*(S+1)>m) S--;
			cout<<S;
		}
	}
	return 0;
} 
