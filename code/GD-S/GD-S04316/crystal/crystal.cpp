#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500100];
int main(){
	ll i,j;
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll p=n,ans=0;
	for(i=n;i>=1;i--){
		while(p-1>=1&&m>=a[i]-a[p-1]) m-=a[i]-a[p-1],p--;
		ans=max(ans,i-p+1);
		m+=(a[i]-a[i-1])*(i-p);
	}
	cout<<ans;
	return 0;
}
