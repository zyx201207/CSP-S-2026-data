#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a1,a2,ans;
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a1+=m;
	ll j=0;
	for(ll i=1;i<=n;i++){
		a1+=a[i];
		a2=a[i];
		if(a1==a2*(i-j)){
			ans=max(ans,(i-j));
			if(a[i+1]!=a[i]) j++;
			a1-=a[j];
		}
		if(a1<a2*(i-j)){
			j++;
			a1-=a[j];
			break;
		}
	}
	cout<<ans;
	return 0;
}
