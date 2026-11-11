#include<bits/stdc++.h>
using namespace std;
int sum[300005];
stack<int> q;
int n,m,a[500005];
int b[300005];
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		
		fill(b+1,b+n+1,0);
		int t=1;
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==0)
			{
				b[a[j]]=t;
				t++;
				int t1=a[j];
				q.push(t1);
			}
			else
			{
				while(q.top()!=a[j])
				{
					q.pop();
				}
				q.pop();
				q.push(a[j]);
				b[a[j]]=0;
			}
		}
		while(!q.empty())
		{
			sum[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
