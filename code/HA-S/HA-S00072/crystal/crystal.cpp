#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+100;
ll n,m;
ll a[N];
ll l,r;
ll ans=0;
ll s[N]; 
ll d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	
	for(int i=2;i<=n;i++)
	d[i]=a[i]-a[i-1];
	
	for(int i=1;i<=n;i++)
	s[i]=s[i-1]+d[i]*(i-1);
	
	for(int i=1;i<=n;i++){
		ll p=lower_bound(s+1,s+i+1,s[i]-m)-s;
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	return 0;
}
