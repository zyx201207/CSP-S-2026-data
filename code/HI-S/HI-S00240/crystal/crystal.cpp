#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[500005],h=1;
	cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	long long mn=INT_MAX,mid=0;
	for(long long i=0;i<n;i++) 
	{
		long long sum=0;
		for(long long j=0;j<n;j++)
		{
			if(i!=j)
			{
				int x=a[i]-a[j];
				if(x<0) x=0-x;
				sum+=x;
			}
		}
		if(sum<mn)
		{
			mn=sum;
			mid=i;
		}
	}
	long long r=mid,l=mid;
	while(a[r+1]==mid)
	{
		r++;
		h++;
	} 
	while(a[l-1]==mid)
	{
		l--;
		h++;
	} 
	while(l-1>=0&&r+1<n)
	{
			if((m-(a[mid]-a[l-1])>=0)&&(a[mid]-a[l-1]<=h*(a[r+1]-a[mid])))
			{
				l--;
				m=m-(a[mid]-a[l]);
				h++;
			}
			else if(m-h*(a[r+1]-a[mid])>=0&&(a[mid]-a[l-1]>=h*(a[r+1]-a[mid])))
			{
				r++;
				m=m-h*(a[r+1]-a[mid]);
				h++;
			}
			else 
			{
				break;
			}
	}
	cout<<h;
	return 0;
}
