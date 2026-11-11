#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500010],ans,flaga=1,flagb=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			flaga=0;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]!=a[1]-a[0]){
				flagb=0;
		}
	}
	if(flaga==1){
		cout<<n;
	}
	else if(flagb==1){
		ll d=a[1]-a[0];
		m/=d;
		for(ll i=0;i<=n;i++){
			if(m<(i*(i+1))/2){
				cout<<i;
				break;
			}
		}
	}
	else{
		for(ll i=1;i<=n;i++){
			ll cnt=0;
			for(ll j=i;j>=1;j--){
				if(cnt+a[i]-a[j]>m){
					ans=max(ans,i-j);
					break;
				}
				if(j==1){
					ans=max(ans,i);
				}
				cnt+=a[i]-a[j];
			}
		}
		cout<<ans;
	}
	return 0;
}//5 8 -3 -1 2 2 7
//5 5 1 2 4 8 9
