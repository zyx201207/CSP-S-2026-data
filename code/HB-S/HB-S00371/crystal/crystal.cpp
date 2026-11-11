#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N];
ll s[N],s1[N];
ll maxx=INT_MIN;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	cin>>a[1];
	for(ll i=2;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]-a[i-1];
		s1[i]=s1[i-1]+s[i];
	}
	sort(a+1,a+1+n);
	for(ll i=2;i<=n;i++){
		for(ll j=1;j<i;j++){
			if(s1[i]-s1[j]+s[i]<=m) maxx=max(maxx,i-j+1);
		}	
	}
	cout<<maxx;
	return 0;
}
