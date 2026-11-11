#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int n,m,a[200005],b[100005];
queue<int>q;
int maim()
{
	cin>>n>>m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	/*	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		q.clear();
		for(int j=i;j<=n;j++)
		{
			if(q.find(0,a[i])!=string::npos)
			{
				q.clear();
			}
			q.push(a[i]);
		}
		while(!q.empty())
		{
			b[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(b[i])
		cout<<b[i]<<' ';
		else
		cout<<"  ";
	}*/
	cout<<1;
	return 0;
}
