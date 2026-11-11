#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],s,c[300010];
bool f[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]=1;
	}
	for(int x=1;x<=n;x++)
	{
		for(int i=x;i<=n;i++)
		{
			if(f[a[i]]==1)
			{
				b[++s]=a[i];
				f[a[i]]=0;
			}
			else if(f[a[i]]==0)
			{
			
				for(int j=1;j<=s;j++)
				{
					if(b[j]==a[i])
					{
						for(int k=j+1;k<=s;k++)
						{
							b[k]==0;
							f[b[k]]=1;
						}
						s-=(s-j);
						break;
					}
				}
			}
		}
		for(int i=1;i<=s;i++)
		{
			c[b[i]]++;
		}
		memset(b,0,sizeof(b));
		memset(f,1,sizeof(f));
		s=0;
	}
	for(int i=1;i<m;i++)
	{
		cout<<c[i]<<" ";
	}
	cout<<c[m];
	return 0;
} 


