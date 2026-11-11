#include<bits/stdc++.h>
using namespace std;
int n,m;
stack<int> s;
int a[500010],b[500010];
bool c[300010];
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
			if(c[a[j]]==true)
			{
				while(s.top()==a[j])
				{
					c[s.top()]=false;
					s.pop();
				}
				s.pop();
			}
			s.push(a[j]);
			c[a[j]]=true;
		}
		while(!s.empty())
		{
			b[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<b[i];
	}
	return 0;
}
