#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=5e5+10;
long long a[maxn],b[maxn],n,m,ans=0,s;//a[]存数据  b[]为前缀和 

long long find(long long x)
{
	long long l=1,r=x,mid,t,sum;
	while(l+1<r)
	{
		mid=l+(r-l)/2,t=x-mid+1,sum=b[x]-b[mid-1];
		if(a[x]*t-sum<=m)//可行 
		{
			r=mid;
		}
		else
		{
			l=mid;
		}
		//cout<<x<<' '<<l<<' '<<r<<'\n';
	}
	t=x-l+1,sum=b[x]-b[l-1];
	if(a[x]*t-sum<=m)
		return x-l+1;
	else
		return x-r+1;
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
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]+b[i-1];
	}
	for(long long i=1;i<=n;i++)
	{
		s=find(i);
		ans=max(ans,s);
	}
	cout<<ans;
	
	return 0;
} 
