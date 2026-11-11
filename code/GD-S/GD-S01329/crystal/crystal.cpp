#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
ll a[5000005];	
int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool canA=true;ll x;
	ll n,m;cin>>n>>m;ll flag2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];	x=a[1];
		if(a[i]>=0)flag2+=a[i];
		if(x!=a[i])canA=false;
	}
	
	if(m>=flag2){
		cout<<n;return 0;
	}else
	if(canA){//A
		cout<<n;return 0;
	}
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1])continue;
		ll cnt=0;ll mn=m;
		for(int j=i;j>=1;j--){
			if(a[j]==a[i])cnt++;
			else if(mn-(a[i]-a[j])>=0){
				cnt++;
				mn-=(a[i]-a[j]);
			}
		}
		ans=max(cnt,ans);
	}
	cout<<ans;

return 0;
} 
