#include <iostream>
#include <algorithm>
using namespace std;
using ll=long long;
ll n,a[500005],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll s1=0,in=1,ans=1;
	for(ll i=1;i<=n;i++){
		s1+=(a[i]-a[i-1])*(i-in);
		while(s1>m){
			s1-=a[i]-a[in];
			in++;
		}
		ans=max(ans,i-in+1LL);
	}
	cout<<ans<<endl;
	return 0;
} 
