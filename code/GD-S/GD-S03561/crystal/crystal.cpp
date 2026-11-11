#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
ll a[500005],q[500005];
ll l,r,ans=-1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++)cin>>a[i];
	
	
	sort(a+0,a+n);
	for(ll i=1;i<=n;i++)q[i]=q[i-1]+a[i-1];
	for(l;l<n;l++){
		ll sum=0;
		r=l;
		ll pos=n-1;
		ll mid=0;
		while(r<=pos){
			mid=(r+pos)/2;
			ll temp;
			temp=(mid-l)*a[mid]-q[mid]+q[l];
			sum+=a[mid];
			if(temp<=m){
				ans=max(ans,mid-l+1);
				r=mid+1;
				
			}
			else pos=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
