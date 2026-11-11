//GZ-J00006 观山湖中学 吴俊辰 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll>a(n+1);
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	ll ans=a[n];
	for(ll i=n-1;i>=n-m+1;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
