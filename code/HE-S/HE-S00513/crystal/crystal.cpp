#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
bool f=0;
struct cry{
	ll e;
	ll cha;
}a[500005];
bool cmp(cry x,cry y){
	return x.e<y.e;
}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;cin>>a[1].e;
	for(ll i=2;i<=n;i++){
		cin>>a[i].e;
		if(a[i].e!=i){
			f=1;
		}
}
if(f){
		sort(a+1,a+n+1,cmp);
		bool f2=0;
	for(ll i=2;i<=n;i++){
		a[i].cha=a[i].e-a[i-1].e;                                         
	}
		for(ll i=1;i<=n;i++){
		ll sum=0;
		ll num=0;
	   for(ll j=i;j<=n;j++){
	sum=sum+a[j].cha*(j-i);
	   	if(sum>m){
	   	break;
		   }
		num++;
	   }
	   ans=max(ans,num);
	}
	cout<<ans;	
}
	else{
		for(ll i=2;i<=n;i++){
	a[i].cha=a[i].e-a[i-1].e;
}
	for(ll i=1;i<=n;i++){
	ll sum=0;
	ll num=0;
	for(ll j=i;j<=n;j++){
	sum=sum+a[j].cha*(j-i);
	if(sum>m){
	break;
		}
	num++;
	}
	ans=max(ans,num);
}
   cout<<ans;
}
	return 0;
} 
