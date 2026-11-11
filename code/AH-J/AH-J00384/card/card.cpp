#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[100005],s1,b[100005],c[100005];
	cin>>n>>m;
	s1=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(n--)
	{
		for(int i=s1-n;i<=n;i++)
		{
			b[i]=a[i];
			for(int j=i;i>=s1-n;j--)
			{
				if(b[j]==b[i])
				{
					for(int k=i;k>j;k--)
					{
						b[k]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0)
			{
				c[i]++;
				}
			}
		for(int i=1;i<=n;i++)
		{
			b[i]=0;
			}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<c[i]<<" ";
		}
}
