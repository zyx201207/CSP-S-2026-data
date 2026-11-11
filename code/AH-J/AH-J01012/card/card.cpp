#include<bits/stdc++.h>
using namespace std;
long long n,m,u[500010],a[300010],b[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	stack<long long>s;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>u[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[u[j]]==0)
			{
				a[u[j]]++;
				s.push(u[j]);
			}
			else
			{
				while(1)
				{
					a[s.top()]=0;
					if(s.top()==u[j])
						break;
					s.pop();
				}
				a[u[j]]=1;
			}
			
		}
		while(s.empty()==0)
		{
			b[s.top()]++;
			a[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}
