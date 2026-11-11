#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005],d[100005];
int main()
{
	freopen("card1.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int i=0;
	int o=n;
	int u=1;
	int p=0;
	while(o--)
	{
		if(i>=1&&!p)
		{
			for(int j=1;j<=n;j++)
			{
				d[j]=c[j];
			}
		}
		if(!p){
			i++;
		}
		
		int b[500005],c[500005];
		for(int j=u;j<=n;j++)
		{
			b[a[j]]++;
			c[a[j]]++;
			if(b[a[j]]==2)
			{
				u=j;
				p=1;
				break;
			}
		}
		if(!p)
		{
			u=i;
			
		}
	}
	for(int j=1;j<=n;j++)
	{
		cout<<d[j]<<" ";
	}
	return 0;
}
