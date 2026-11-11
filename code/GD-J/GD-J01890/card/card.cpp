#include <bits/stdc++.h>
using namespace std;
int m,n;
int a[500005],b[300005];
int c[300005];
stack<int> s;
void dp(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(c[a[i]]==1)
		{
			while(s.top()!=a[i])
			{
				c[s.top()]=0;
				s.pop();
			}
		}
		else{
			s.push(a[i]);
			c[a[i]]=1;
		}
	}
	while(!s.empty())
	{
		c[s.top()]=0;
		b[s.top()]++;
		s.pop();
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	return 0;
}
