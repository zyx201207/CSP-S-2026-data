#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
int n,m;
ll a[500005];
ll b[500005];//long long 
ll ans;/**/
bool pd(ll i,ll j){
	if(i<=0||j>n)return 0;
	if(a[j]*(j-i+1)-(b[j]-b[i-1])<=m){
		return 1;
	}
	return 0;
}
ll erfen(ll i){
	ll l=1,r=i;
	while(l<r){
		ll mid=(l+r)/2;
		if(pd(mid,i)){
			r=mid;
		}else
			l=mid+1;          
		//cout<<l<<" "<<r<<endl;
	}
	if(pd(l-1,i))l--;
	return i-l+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=n;i>=1;i--){
		//cout<<"i="<<i<<":";
		ans=max(ans,erfen(i));
		if(ans>=i)break;
		//cout<<"ans="<<ans<<"\n-------------\n";
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9


5 8
-3 -1 2 2 7
*/