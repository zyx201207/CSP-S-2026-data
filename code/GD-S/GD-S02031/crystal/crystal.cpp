#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500050],b[500050],c[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m,ans=0,ab=1;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
		if(i>=2&&c[i]!=c[i-1]){
			ab=0;
		}
	}
	if(ab){
		ll dc=c[1],i=1;
		while(m>=i*(i+1)/2*dc){
			i++;
		}
		cout<<i;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		ll k=0,l=m;
		for(ll j=1;j<=n;j++){
			b[j]=a[i]-a[j];
		}
		sort(b+1,b+1+n);
		for(ll j=1;j<=n;j++){
			if(l>=b[j]&&b[j]>=0){
				k++;
				l-=b[j];
			}
		}
		ans=max(ans,k);
	}
	cout<<ans;
	return 0;
}
