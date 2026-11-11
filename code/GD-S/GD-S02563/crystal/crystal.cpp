#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500010],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];sort(a+1,a+n+1);
	for(ll l=1,r=2,c=0;r<=n;r++){
		c+=(r-l)*(a[r]-a[r-1]);
		while(c>m)c-=a[r]-a[l++];
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
