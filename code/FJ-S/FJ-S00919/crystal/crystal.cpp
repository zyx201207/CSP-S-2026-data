#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=500005,mid;
	while(l<=r) 
	{
		mid=(l+r)/2;
		long long maxn=0,minn=1e18;
		for(int i=1;i<=n-mid+1;i++)
		{
			for(int j=1;j<=i+mid-1;j++)
			{
				maxn+=a[i+mid-1]-a[j];
			}
			if(minn>maxn) minn=maxn;
		    maxn=0;
		}
		if(minn>m) r=mid-1;
		else if(minn<m) l=mid+1;
		else if(minn==m)
		{
			cout<<mid<<endl;
			return 0;
		}
	}
	cout<<l<<endl;
	return 0;
}
