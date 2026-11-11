#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N];
ll pre[N],bu[N];
bool check(int x)
{
	for(int i=1;i<n;i++)
	{
		int j=i+x-1;
		if(j>n)
			break;
		ll mf=bu[j]-(i-1)*a[j]+pre[i-1];
		if(mf<=m)
		{
			//cout<<i<<" "<<j<<'\n';
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
		bu[i]=bu[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=max(ans,mid);
		}
		else 
			r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}
