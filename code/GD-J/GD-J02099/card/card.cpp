#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],h=0,l=0;
queue<int> d;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			d.push(a[j]);
			if(a[j]==a[i] && j!=i)
			{
				d.pop();
				while(d.front()!=a[i])
				{
					d.pop();
				}
			}
		}
		for(int i=0;i<d.size();++i)
		{
			b[d.front()]++;
			d.pop();
		}
		while(!d.empty())
		{
			d.pop();
		}
	}
	for(int i=1;i<=m;++i)
	{
		cout<<b[i]<<" ";
	}
	return 0;
 } 
