#include<bits/stdc++.h>
using namespace std;
#define fname "and"
using ll=long long;
ll n,m,a[200005],ans=1e9;
int main(){
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=n;i>=n-m+1;i--){
		ans=min(ans,a[i]);
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
