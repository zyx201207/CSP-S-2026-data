#include <bits/stdc++.h>
using namespace std;
int d[300005],a[500005],n,m,f[300005];

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
		stack <int> q;
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]])
			{
				while(q.top()!=a[j])
				{
					f[q.top()]=0;
					q.pop();
					
				}
			}
			else
			{
				f[a[j]]=1;
				q.push(a[j]);
			}
		}
		for(int j=1;j<=m;j++)
		{
			d[j]+=f[j];
		}
	}
	for(int i=1;i<=m;i++)cout<<d[i]<<" ";
	fclose(stdin);
	fclose(stdout);
}
