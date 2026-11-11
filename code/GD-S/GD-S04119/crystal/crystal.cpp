#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],s[500005],maxn=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=n;i>=1;i--){
		ll l=1,r=i-1,mid=0,ans=1;
		while(l<=r){
			mid=(l+r)>>1;
			ll need=1ll*(a[i]*(i-mid)-(s[i-1]-s[mid-1]));
			if(need<=m)ans=i-mid+1,r=mid-1;
			else l=mid+1;
		}
		maxn=max(ans,maxn);
	}
	cout<<maxn;
	return 0;
} 
