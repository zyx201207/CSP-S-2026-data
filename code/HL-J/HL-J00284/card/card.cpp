#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[300005],c[300005];
stack <int> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
			b[i]=0;
		for (int i=k;i<=n;i++)
		{
			b[a[i]]++;
			if (b[a[i]]>1)
			{
				while(q.top()!=a[i])
				{
					int x=q.top();
					b[q.top()]--;
					q.pop();
				}
				b[q.top()]--;
				q.pop();
			}
			q.push(a[i]);
		}
		while(!q.empty())
		{
			int l=q.top();
			c[l]++;
			q.pop();
		}
		
	}
	for (int i=1;i<=m;i++)
		cout <<c[i]<<" ";
	return 0;
}
