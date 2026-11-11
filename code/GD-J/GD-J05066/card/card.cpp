#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[200005];
bool p[500005];
stack <int> s;
int main()
{
	freopen("card.out","w",stdout);
	freopen("card.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(p[a[j]])
			{
				while(1)
				{
					if(s.top()!=a[j])
					{
						p[s.top()]=0;
						s.pop();
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				s.push(a[j]);
				p[a[j]]=1;
			}
		}
		while(!s.empty())
		{
			for(int j=1;j<=m;j++)
			{
				if(s.top()==j)
				{
					sum[j]++;
					p[s.top()]=0;
					s.pop();
					continue;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
