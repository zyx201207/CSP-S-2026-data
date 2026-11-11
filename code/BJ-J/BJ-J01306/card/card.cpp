#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],b[300010],c[300010];
stack<long long> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int i=1;i<=m;i++)
		{
			b[i]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==1)
			{
				for(int k=j-1;k>=i;k--)
				{
					if(a[k]==a[j])
					{
						break;
					}
					else
					{
						b[a[k]]=0;
					}
				}
				b[a[j]]=1;
			}
			else
			{
				b[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			c[j]+=b[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
