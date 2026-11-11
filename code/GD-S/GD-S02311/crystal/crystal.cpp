#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll l=1,res=0;
	ll ans=0;
	for(int r=2;r<=n;r++){//ÏòÓÒÍØÕÅ 
		res+=(r-l)*(a[r]-a[r-1]);
		while(1){
			if(res<=m) break;
			l++;
			res-=(a[r]-a[l-1]);
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
