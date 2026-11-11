#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[2222222],b[2222222],ans,maxn,sum,gp2,id,sh;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	maxn=a[n];
	for(ll i=1;i<=n;i++){
		b[i]=a[n]-a[i];
	}
	id=n;
	sh=m;
	for(ll i=n;i>=1;i--){
		sum=sh;
		gp2=i-id;
		for(ll u=id;u>=1;u--){
			if(sum>=(b[u]-b[i])){
				gp2++;
				sum-=(b[u]-b[i]);
			}
			else{
				id=u;
				sh=sum+(i-u)*(a[i]-a[i-1]);
				break;
			}
		}
		ans=max(ans,gp2);
	}
	cout<<ans;
	return 0;
}
