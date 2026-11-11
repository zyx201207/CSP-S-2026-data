#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+9;

ll n,ans;
ll a[N];
char c[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		 cin>>a[i]>>c[i];
	 }
	for(ll i=1,j=n;i<j;  ){
		ll x=min(a[i],a[j]);
		if(c[i]!=c[j]) ans+=x;
		a[i]-=x,a[j]-=x;
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	
	cout<<ans;
	return 0;
}
//Trick||Treat!
