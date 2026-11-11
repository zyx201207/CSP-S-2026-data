#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll ans;
ll a[500005];
ll s[500005];
bool check(int len){
	for(int start=1;start<=n-len;start++){
		ll end=len+start-1;
		if(a[end]*len-(s[end]-s[start-1])<=m){
			return 1;
		}
	} 
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
//		cout<<s[i]<<" "<<a[i]<<endl;
	}
	ll l=0,r=n,mid;
	while(r>l){
		mid=(l+r)/2;
//		cout<<"l:"<<l<<" r:"<<r;
		if(check(mid)){
			l=mid+1; ans=max(ans,l);//  cout<<"ans:"<<ans<<" ";
		}	
		else{
			r=mid-1; 
		}
//		cout<<"mid:"<<mid; 
//		cout<<endl;
	}
	cout<<ans;
	return 0;
} 
