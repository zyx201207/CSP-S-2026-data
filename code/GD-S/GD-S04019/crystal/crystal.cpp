#include<bits/stdc++.h>
using namespace std;
const int M=500005;
typedef long long ll;
ll a[M],b[M],n,m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n,m;
	cin>>n>>m;
	if(n==1)
	{
		cout<<1;
		return 0;
	} 
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
//	cout<<a[1]<<' ';
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];	
	if(b[n]==(a[1]+a[n])*n/2)
	{
		ll k=b[n]/n;
		int mid=n/2,t=0;
		ll cnt=0;
		for(int i=mid+1,j=mid;i<=n,j>=1;i++,j--)
		{
			if(cnt+abs(a[i]-k)<=m) ans++,cnt+=abs(a[i]-k);
			else t=1;
			if(cnt+abs(a[j]-k)<=m) ans++,cnt+=abs(a[j]-k);
			else if(t==1)
			{
				cout<<ans;
				return 0;
			}
			t=0;
		}
	}
//	cout<<b[5000]-b[2501]-2499*a[2501]<<'\n';
//	cout<<2500*a[2501]-b[2500]+b[5000]-b[2501]-2499*a[2501]<<'\n';
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ll k=(i+j)/2,cnt=0;
			ll l=k-i,r=j-k;
			cnt=l*a[k]-b[k-1]+b[j]-b[k]-r*a[k];
			if(i==1&&j==3) cout<<cnt<<'\n';
//			if(i==1&&j==5000) cout<<l*a[k]-b[k-1]<<'\n';
			if(cnt<=m) 
			{
				ans=max(ans,1ll*(j-i+1));
			}
		}
	} 
	cout<<ans;
	return 0;
}
/*
	10 6
	1 2 3 4 5 6 7 8 9 10
	5 5
	1 2 4 8 9
	5 8
    -1 -3 2 2 7
	*/

