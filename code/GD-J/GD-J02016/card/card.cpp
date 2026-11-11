#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int t=1;t<=n;t++)
	{
		int b[m+5]={};
		queue<int> q;
		while (!q.empty()) q.pop();
		for (int i=t;i<=n;i++)
		{
			if (b[a[i]]==0)
			{
				q.push(a[i]);
				b[a[i]]++;
			}
			else
			{
				while (q.front()!=a[i])
				{
					b[q.front()]--;
					q.pop();
				}
				q.pop();
				q.push(a[i]);
			}
		}
		for (int i=1;i<=m;i++)
			if (b[i]) ans[i]++;
	}
	for (int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
