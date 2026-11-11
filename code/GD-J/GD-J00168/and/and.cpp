#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[2000000+10];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll ans=a[n];
	for(ll i=n-1;i>=m;i--){
		ans&=a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
