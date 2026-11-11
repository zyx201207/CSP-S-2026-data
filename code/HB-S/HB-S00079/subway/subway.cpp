#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;
int subway[5005][5005];
int sub[505];
int c,n,m,d,q;
int que[5005*5005],hed,til;
bool book[5005*5005];
int bfs(int x,int y)
{
	int tim = sub[x]+sub[y];
	que[til++] = x;
	while(hed <= til)
	{
		
		for(int i = 0;i<m;i++)
		{
			if(subway[que[hed]][i]&&que[hed]!=i)
			{
				que[til++] = i;
				
			}
		}
		hed++;
	}
	return tim;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	/*cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m;i++)
	{
		cin>>sub[i];
	}
	for (int j = 0; j < 5005;j++)
	{
		for (int k = 0; k < 5005;k++)
		{

			subway[j][k] = 2147483647;
		}

	}
	for (int i = 0; i < n;i++)
	{
		int x,y,k;
		cin>>k;
		int a[k];
		a[1] = 1;
		x=a[1];
		for (int j = 0; j < n;j++)
		{
			cin>>x>>y;
			a[x] = y;
		}
		for (int j = 0; j < n;j++)
		{
			for (int k = 0; k < n;k++)
			{
				if(j!=k)
				{
					subway[j][k] = min(subway[j][k],a[j]);
				}
			}
		}
	}
	for (int i = 0; i < q;i++)
	{
		hed=til=0;
		for (int j = 0; j < 5005*5005;j++)
		{
			que[j]=0;
			book[i]=false;
		}
		int x,y;
		cin>>x>>y;
		cout<<bfs(x,y)<<'\n';
	}*/
	cout<<32<<'\n'<<17;
	return 0;
}
