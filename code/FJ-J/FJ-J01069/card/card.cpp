#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],b[100001],c[100001],d[100001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int s=0;
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]]==1)
			{
				while(b[s]!=a[j])
				{
					c[b[s]]=0;
					b[s]=0;
					s--;				
				}
				b[s]=0;
				s--;
				c[a[j]]=1;
				s++;
				b[s]=a[j];
			}
			else
			{
				c[a[j]]=1;
				s++;
				b[s]=a[j];
			}
		}
		for(int j=1;j<=s;j++)
		{
			d[b[j]]++;
		}
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
	}
	for(int i=1;i<=m;i++)
	{
		cout<<d[i]<<" ";
	}
	return 0;
}
