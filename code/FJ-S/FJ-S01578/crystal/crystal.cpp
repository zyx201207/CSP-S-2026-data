#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans=1;
ll a[500010];
ll b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll i=0,j=1,x=0;
	for(;i<n;i++){
		while(j+1<n&&((a[j+1]-a[j])*(j-i+1)+x<=m)){
			j++;
			x+=(a[j]-a[j-1])*(j-i);
		}
		ans=max(ans,j-i+1);
		x-=(a[j]-a[i]);
	}
	cout<<ans;
	return 0;
}
