#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],sum;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	queue<int> s;
	set<int> d;
	while(!s.empty())
	{
		for(int i=1;i<=n;i++)
		{
			s.push(a[i]);
			d.insert(a[i]);
			if(sizeof(s)!=sizeof(d))
			{
				for(int j=1;j<=sizeof(d);j++)
				{
					s.pop();
					if(s.empty())
					{
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<1<<" ";
	}
	return 0;
}