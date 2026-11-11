#include<bits/stdc++.h>
using namespace std;
long long a[500001];
long long b[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool f=1;
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=i+1)
		{
			f=0;
		}
	}
	if(f==1)
	{
		cout<<n;
		return 0;
	}
	sort(a,a+n);
	long long l=0;
	for(int i=n-1;i>=0;i--)
	{	
		b[l]=a[i];
		l++;
	}
	long long k=0,s=0;
	for(int i=0;i<n;i++)
	{
		long long h=m;
		//cout<<b[i]<<":";
		for(int j=i;j<n;j++)
		{
			if(h<b[i]-b[j])
			{
				break;
			}else
			{
				k++;
				//cout<<b[j]<<" ";
				h=h-(b[i]-b[j]);
			}
		}
		if(k>=s)
		{
			s=k;
		}
		//cout<<endl;
		k=0;
	}
	cout<<s;
	return 0;
}
