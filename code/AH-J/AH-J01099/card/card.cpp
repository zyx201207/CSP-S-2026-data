#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],f[300005];
int n,m;
void play(int j)
{
	stack<int> s;
	for (int i=j;i<=n;i++)
	{
		if (b[a[i]]==1)
		{
			while (s.top()!=a[i])
			{
				b[s.top()]=0;
				s.pop();
			}
			s.pop();
		}
		s.push(a[i]);
		b[a[i]]=1;
	}
	for (int i=1;i<=m;i++)
	{
		if (b[i]==1)
		{
			f[i]++;
		}
		b[i]=0;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		play(i);
	}
	for (int i=1;i<=m;i++)
	{
		cout<<f[i]<<" ";
	}
	return 0;
}
