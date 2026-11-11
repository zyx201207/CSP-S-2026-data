#include<bits/stdc++.h>
using namespace std;
int a[500005],s[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int j=0;
	while(j<n)
	{
		int b[500005];
		j++;
		int c=j-1;
		for(int i=j;i<=n;i++)
		{
			bool d=0;
			for(int k=j;k<=c;k++)
			{
				if(a[i]==b[k])
				{
					c=k;
					d=1;
					break;
				}
			}
			if(d==0)
			{
				c++;
				b[c]=a[i];
			}
		}
		for(int i=j;i<=c;i++)
		{
			s[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<' '; 
	}
} 
