#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],dp,maxn=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		m-=dp*(a[i]-a[i-1]);
		dp++;
		if(m<0)
			while(m<0){
				dp--;
				m+=a[i]-a[i-dp];
			}
		maxn=max(maxn,dp);
	}
	cout<<maxn;
	return 0;
} 
