#include<bits/stdc++.h>
#define ll long long 
using namespace std;
bool cmp(ll num1,ll num2){
	return num1>num2;
}
const ll N=5e5+5;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(a,0,sizeof(a));
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ll ans=0,p=1;
	for(int i=1;i<=n;i++){
		while((m>=a[i]-a[p])&&(p<=n)) m=m-(a[i]-a[p]),p++;
		ans=max(ans,p-i);
		m=m+(a[i]-a[i+1])*(p-i-1);
	} 
	cout<<ans;
	return 0;
}
