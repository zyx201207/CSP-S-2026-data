#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,arr[500005],d[500005];
bool check(ll x){
	ll res=0,p=k;
	for(int i=1;i<=x;i++){
		if(p-i*d[i]<res) p-=i*d[i];
		else res+=i*d[i];
	}
	if(res<=p) return 1;
	for(int i=2;i<=n-x+1;i++){
		res-=arr[i+x-2];
		if(p-x*d[i+x-1]<res) p-=x*d[i+x-1];
		else return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>arr[i];
	sort(arr+1,arr+1+n);
	for(int i=2;i<=n;i++) d[i-1]=arr[i]-arr[i-1];
	ll l=0,r=n-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
