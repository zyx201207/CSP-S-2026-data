#include<bits/stdc++.h>
using namespace std;
stack<int>s;
int n,m,a[500005],b[500005],c[500005],d[500005];
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
		while(!s.empty())
		{
			s.pop();
		}
		for(int j=1;j<=n;j++)
		{
			b[a[j]]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==1)
			{
				while(!s.empty())
				{
					if(s.top()==a[j])
					{
						s.pop();
						break;
					}
					s.pop();
				}
			}
			s.push(a[j]);
			b[a[j]]=1;
		}
		for(int j=1;j<=m;j++)
		{
			d[j]=c[j]+1;
		}
		while(!s.empty())
		{
			c[s.top()]=d[s.top()];
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
} 
	
