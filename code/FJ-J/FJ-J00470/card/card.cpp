#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
int c[500005],d[500005];
stack<int> b;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int t=0;t<n;t++)
	{
		for(int e=t;e<n;e++)
		{
			if(d[a[e]]==1)
			{
				while(b.top()!=a[e]&&!b.empty())
				{
					d[b.top()]=0;
					b.pop();
				}
				d[b.top()]=0;
				b.pop();
				b.push(a[e]);
				d[a[e]]=1;
			}
			else
			{
				b.push(a[e]);
				d[a[e]]=1;
			}
		}
		for(int i=0;i<=m;i++)
		{
			d[i]=0;
		}
		if(!b.empty())
		{
			while(!b.empty())
			{
				c[b.top()]++;
				b.pop();
			}
		}
	}
	for(int i=1;i<=m;i++)
	cout<<c[i]<<' ';
	return 0;
}
