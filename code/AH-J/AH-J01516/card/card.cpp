#include<bits/stdc++.h>
using namespace std;
int a[500001],b[500001],t[500001];
bool f[500001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		int c=0;
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==1)
			{
				int dx=0;
				for(int l=1;l<=c;l++)
				{
					if(dx!=0)
					{
						f[b[l]]=0;
						b[l]=0;
					}
					if(b[l]==a[j])
					{
						dx=l;
					}
				}
				c=dx;
			}
			else
			{
				f[a[j]]=1;
				c++;
				b[c]=a[j];
			}
		}
		for(int j=1;j<=k;j++)
		{
			if(f[j]==1)
			{
				t[j]++;
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		cout<<t[i]<<" ";
	}
}
