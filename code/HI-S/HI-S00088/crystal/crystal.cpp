#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
typedef long long ll;
ll n,m;
ll a[maxn],x[maxn];
ll calc(int k)
{
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		ans+=x[i];
	}
	return ans;
}
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	ll cnt=1,t=m;
	for(int i=n/2;i>=1;i--)
	{
		if(a[n/2]-a[i]<=t)
		{
			t-=a[n/2]-a[i];
			cnt++;
		}
	}
//	for(int i=1;i>=n;i++)
//	{
//		x[i]=a[i+1]-a[i];
//	}
//	ll sum=0,minn=1e9,id;
//	for(int i=1;i<=n;i++)
//	{
//		sum=calc(i);
//		if(sum<minn)
//		{
//			minn=sum;
//			id=i;
//		}
//	}
//	for(int i=id-1;i>=1;i--)
//	{
//		if(a[id]-a[i]<=t)
//		{
//			t=t-(a[id]-a[i]);
//			cnt++;
//		}
//	}
	cout<<cnt;
	return 0;
}
