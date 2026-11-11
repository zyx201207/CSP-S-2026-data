#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],c[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int b[500010];
		for(int j=i;j<+n;j++)
		{
			a[j]=b[j];
			for(int x=1;x<j;x++)
			{
				if(b[x]==b[j]) 
				{
					for(int y=x;y<=j;y++) b[y]=0;
				}
			}
		}
		for(int s=i;s<=n;s++)
		{
			if(b[s]!=0)
			{
				c[b[s]]++;
			}
		}
	}
	 for(int i=0;i<=n;i++)
		{
			if(c[i]!=0)
			{
				cout<<c[i]<<" ";
			}
		}
	return 0;
}
