#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[300005];
queue<int> q; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(q.find(a[j])==-1)
			{
				q.push(a[j]);
			}
			else
			{
				while(q.find(a[j])!=-1)
				{
					q.pop();
				}
			}
		}
		while(!q.empty())
		{
			f[q.tow()]++;
			q.pop();
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<f[i]<<" ";
	}
}
