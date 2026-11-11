#include<bits/stdc++.h>
using namespace std;
long long a[500010],c[500010];
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	long long n,m,d=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	while(d++!=n)
	{
		for(int i=d-1;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			if(a[i]==a[j])
			{
				for(int h=j+1;h<i;j++)
				{
					a[h]=0;	
				}
			}
		}
		for(int i=0;i<=n;i++)
		{
			c[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
