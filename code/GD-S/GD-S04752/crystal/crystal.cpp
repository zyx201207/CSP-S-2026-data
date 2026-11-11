//crystal
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500050];
ll c[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	c[0]=0;
	ll j=0;
	ll ans=0;
	ll sm=0;
	for(int i=1;i<=n;i++){
		sm+=(a[i]-a[i-1])*(i-j-1);
		while(sm>m){
			++j;
			sm-=(a[i]-a[j]);
		}
		ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
}
