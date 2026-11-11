#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500001],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		bool z=1;
		ll sum=0,cnt=1;
		for(ll j=i-1;j>0&&z;j--){
			if(sum+a[i]-a[j]<=m)cnt++,sum+=a[i]-a[j];
			else z=0;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
