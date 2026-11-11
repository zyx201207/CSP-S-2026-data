#include <bits/stdc++.h>
using namespace std;
long long n,m,a[550005],d[550005],ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		d[i]=a[i]+d[i-1];
	}
	for(long long i=2;i<=n;i++)
	{
		long long l=1,r=i-1;
		long long mid=(l+r)/2;
		while(l<r)
		{
			//if(i==3) cout<<mid<<" "<<((i-mid)*a[i]-(d[i-1]-d[mid-1]))<<endl;
			long long num=((i-mid)*a[i]-(d[i-1]-d[mid-1]));
			if(num<=m)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
			mid=(l+r)/2;
			//if(i==3) cout<<mid<<" "<<((i-mid)*a[i]-(d[i-1]-d[mid-1]))<<endl;
		}
		if(l>r)
		{
			long long num=(((i-l)*a[i]-(d[i-1]-d[l-1])<=m));
			if(num<=m)
			{
				mid=l;
			}
			else 
			{
				mid=r;
			}
		}
		ans=max(ans,i-mid+1);
		//cout<<i-mid+1<<"  ";
		//cout<<ans<<" ";
	}
	cout<<ans;
 	return 0;
} 
//3 4 3845 315275
