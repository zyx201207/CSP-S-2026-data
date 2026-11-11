#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,b[100000],a[100000];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		a[i]=b[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=j;k>=1;k++)
			{
				if(a[j]==a[k])
				{
					for(int p=k;p<=j;p++)
					{
						a[p]=0;
					}
				}
			}
		}
		int num=0,sum=0,mmm=0;
		for(int u=1;u<=n;u++)
		{
			if(a[u]==b[1]) num++;
			if(a[u]==b[2]) sum++;
			if(a[u]==b[3]) mmm++;
		}
		
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
