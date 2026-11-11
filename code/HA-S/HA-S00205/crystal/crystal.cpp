#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=0;
	ll p=m;
	for(int i=n;i>=1;i--){
		ll k=0;
		p=m;
		if(a[i]-a[i-ans]>p){
			continue;
		}
		for(int j=i;j>=1;j--){
			if(a[i]-a[j]<=p){
				k++;
				p-=(a[i]-a[j]);
			}
		}
		ans=max(ans,k);
	}
	cout<<ans;
	return 0;
}