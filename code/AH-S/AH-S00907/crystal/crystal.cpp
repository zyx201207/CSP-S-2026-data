#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500001],sum[500001],mx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cout<<n<<endl;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	if(a[2]-a[1]<=m) mx=2;
	for(int i=3;i<=n;i++)
	{
		ll l=1,r=i-1,res=i;
		while(l<=r)
		{
			ll mid=l+r>>1;
			ll en=sum[i-1]-sum[mid-1];
			if(a[i]*(i-mid)-en>m) l=mid+1;
			else 
			{
				res=mid;
				r=mid-1;
			}
		}
		mx=max(mx,i-res+1);
	}
	cout<<mx;
	return 0;
}
