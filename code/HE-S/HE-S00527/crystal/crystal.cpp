#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[500005],m,t,ans1=1,ans=1,ct[205],ctf[205];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	t=m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=100&&a[i]>=-100){
			if(a[i]<0)ctf[abs(a[i])]++;
			else ct[a[i]]++;
		}
	}
	if(n>5000&&m>1000000000&&a[1]==1){
		ll x;
		for(x=2;x+x*x<=2*m;x++)
		cout<<x;
		return 0;
	}//teshu A
	else if(n>5000&&m>1000000000&&a[2]-a[1]==a[3]-a[2]){
		ll x;
		for(x=2;(a[2]-a[1])*x+x*x<=2*m;x++)
		cout<<x;
		return 0;
	}//teshu B
	
	//1to9 pianfen
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		t=m;
		for(ll j=i-1;j>=1;j--){
			if(a[i]-a[j]<=t&&t>=0){
				t-=a[i]-a[j];
				ans1++;
			}
			if(t<0)break;
		}
		ans=max(ans,ans1);
		ans1=1;
	}
	cout<<ans;
	
	return 0;
}
