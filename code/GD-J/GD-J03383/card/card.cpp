#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001],c[10001];
vector<int> q;
bool find(int x,int y)
{
	for(int i=1;i<y;i++)
	{
		if(q[i]==x)return 1;
	}
	return 0;
}
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
		for(int j=i;j<=n;j++)
		{
		    if(find(a[j],j-i))
			{
				while(q.back()!=a[j]);
				{
					q.pop_back();
				}
			}
			q.push_back(a[j]);
		}
		while(!q.empty())
		{
			c[q.back()]++;
			q.pop_back();
		}
		while(!q.empty())
		{
			q.pop_back();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
