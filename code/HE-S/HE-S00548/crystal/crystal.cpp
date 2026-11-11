#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m;
ll a[N],d[N];
ll ans[N];
ll ans1=0;
bool bh(){
	ll c=0,cnt=1,b=0;
	for(ll i=2;i<=n;i++){
		for(ll j=i-1;j>=1;j--){
			c+=a[i]-a[j];
			if(c<=m) ans[cnt]++;
			else if(c>m) break;
		}
		c=0;
		cnt++;
	}	 
	for(ll i=1;i<n;i++){
		ans1=max(ans1,ans[i]+1);
	}
	return ans1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(),cout.tie();
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
	}
	bh();
	cout<<ans1;
	return 0;
} 
//Oct31==Dec25?
