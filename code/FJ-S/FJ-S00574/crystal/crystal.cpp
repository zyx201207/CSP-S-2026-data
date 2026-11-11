#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],b[500005],ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(ll i=1;i<=n;i++){
		b[i]+=b[i-1];
	}
	ll l=1,r=1;
	while(r<=n){
		if(l>r) r++;
		if((a[r]*(r-l+1))-(b[r]-b[l-1])<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else l++;
	}
	cout<<ans;
	return 0;
}
