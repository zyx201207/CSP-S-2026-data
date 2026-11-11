#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],b[200010],max1=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
	cin>>a[n];
		b[n]=a[n];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(b[i]%2==b[j]%2) 
			{
				if(a[i]>a[j]&&a[i]>max1) max1=a[i];
				else 
				{
					if(a[j]>max1) max1=a[j];
				}
			}
			b[i]=b[i]/2;
			b[j]=b[j]/2;
		}
	}
	cout<<max1;
	return 0;
}
