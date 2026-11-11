#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[500005];
bool b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int g=1;g<=n;g++)
	{
		memset(b,0,150005);
		for(int i=g;i<=n;i++)
		{
			for(int j=g;j<i;j++)
			{
				if(a[i]==a[j]&&b[j]==1)
				{
					for(int k=j;k<i;k++)
					{
						b[k]=0;
					}
					break;
				}
			}
			b[i]=1;
		}
		for(int i=g;i<=n;i++)
		{
			if(b[i]==1)
			c[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<' ';
	}
	return 0;
}
