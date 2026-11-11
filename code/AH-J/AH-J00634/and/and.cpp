#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,a[100000+10],ans=0,maxn=0;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(maxn<=a[i])maxn=a[i];
		if(i==1)ans=a[i];
		else ans&=a[i];
	}if(m==n){
		cout<<ans;
		return 0;
	}if(m==1){
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+n+1);
	for(ll i=n;i>=1;i--){
		if(i==n-2){
			cout<<a[i];
		}
	}
	return 0;
}
