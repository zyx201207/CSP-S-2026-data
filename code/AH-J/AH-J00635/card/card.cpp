#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],d;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++)
	{
		stack<int>s;
		queue<int>q;
		d=0;
		int f[500005];
		memset(f,0,sizeof(f));
		for(int j=n;j>=i;j--)
		{
			s.push(a[j]);
		}
		while(!s.empty())
		{
			d=s.top();
			s.pop();
			if(f[d]==0)
			{
				q.push(d);
				f[d]=1;
			}
			else
			{
				while(q.front()!=d)
				{
					f[q.front()]=0;
					q.pop();
				}
			}
		}
			while(!q.empty())
			{
				ans[q.front()]++;
				q.pop();
			}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
