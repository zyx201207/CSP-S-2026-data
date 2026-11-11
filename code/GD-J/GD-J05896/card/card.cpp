#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
bool vis[300010];
int ans[500010];
stack < int> s;
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int qq=0,k=0;
	for (int i=1;i<=m;i++)
	{
		for (int q=0;q<=n;q++)
		{
			vis[q]=0;
		}
		for (int j=i;j<=n;j++)
		{
			if (!vis[a[j]])
			{
				vis[a[j]]=1;
				s.push(a[j]);
			}
			else
			{
				k=s.top();
				while (k!=a[j])
				{
					k=s.top();
					s.pop();
					vis[k]=0;
				}
			}
		}
		while (!s.empty())
		{
			qq=s.top();
			s.pop();
			ans[qq]++;
		}
	}
	for (int i=1;i<=n;i++)
	{
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}

