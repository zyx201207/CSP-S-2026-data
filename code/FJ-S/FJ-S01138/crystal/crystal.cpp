#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=5e5+5;
ll n,m,ans=1,a[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(ll l=1,r=2,s=0;r<=n;r++){
		s+=(a[r]-a[r-1])*(r-l);
		if(r-l+1<=ans)continue;
		while(s>m&&l<r)s-=(a[r]-a[l++]);
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
