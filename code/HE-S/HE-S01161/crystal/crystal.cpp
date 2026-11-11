#include<bits/stdc++.h>
using namespace std;
long long int m,n,a[100000005],b,c=0,d,j=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=0;i<=m;i++)
	{
		
		if(m+a[1]>=a[n-i])
		{
			for(int h=1;h<=n+1;h++)
			{
				b=a[n-i];
				
				if(a[j]==a[n-i])
				{
					++j;
					m++;
				}
				a[j]=a[j]+c;
				c=1;
				m--;
				if(m==0)
				{
					break;
				}
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(a[i]==b)
		 d++;
	}
	cout<<d;
	return 0;
}
