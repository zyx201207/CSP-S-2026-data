#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	cin>>n;
	ll sum=0;
	vector<ll> a(n+2);
	vector<char> c(n+2);
	for(int i=0;i<n;i++){
		int now;
		cin>>now;
		a[i]=sum;
		cin>>c[i];
		sum+=now;
	} 
	a[n]=sum;
	ll cnt=0;
	ll ans=0;
	for(int i=0;a[i]+1<=sum/2;i++){
		
		ll l=sum-min(sum/2,a[i+1]),r=sum-a[i];
		int begin=lower_bound(a.begin(),a.end(),l)-a.begin();
		begin=min(begin,n);
		int end=lower_bound(a.begin(),a.end(),r)-a.begin();
		end=min(end,n);
		
		for(int j=begin;j<end;j++){
//			cout<<a[j+1]<<" "<<a[j]<<'\n';
			if(c[j]!=c[i])ans=ans+((min(a[j+1],r)-max(l+1,a[j])))+1;
		}
//		cout<<begin<<" "<<end<<" "<<l<<" "<<r<<'\n';
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}
