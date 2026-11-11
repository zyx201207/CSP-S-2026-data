#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	ll n;
	cin>>n;
	string s="";
	ll sum=0,maxx=-1;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx>500){
		cout<<sum/2;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	ll L=(s.length()-1)/2;
	ll ans=0;
	for(ll i=0;i<=L;i++){
		if(s[i]!=s[sum-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}