#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],b[N],t[N],c[N];
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
		for(int j=i;j<=n;j++)b[j]=0;
		for(int j=i;j<=n;j++)
		{
			c[a[j]]++;
			if(t[a[j]]==0)t[a[j]]=j;
			else
			{
				for(int l=t[a[j]];l<j;l++)
				{
					if(b[l])
					{
						l=b[l];
						continue;
					}
					b[l]=1;
					c[a[l]]--;
					if(t[a[l]]==l)t[a[l]]==0;
				}
				t[a[j]]=j-1;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
} 
