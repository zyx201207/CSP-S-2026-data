#include<bits/stdc++.h>
using namespace std;
int a[500001];
int b[500001];
int ye[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x[m+1]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ye[a[i]]++; 
	}
	int u=n;
	while(u!=0)
	{
		int y=0;
		for(int i=n-u;i<n;i++)
		{
			if(ye[a[i]]>1)
			{
				for(int j=0;j<=y;j++)
				{
					if(a[i]==b[j])
					{
						y=j;
						break;
					}
				}
			}
			b[y]=a[i];
			y++;
		}
		for(int i=0;i<y;i++)
		{
			x[b[i]]++;
		}
		u--;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<x[i]<<" ";
	}
	return 0;
}
