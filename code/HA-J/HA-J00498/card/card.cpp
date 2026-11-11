#include<bits/stdc++.h>
using namespace std;
stack<int>q;
int tot[5000010];
int ans[500010];
int a[5000010];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(tot[a[j]]==0)
				{
					q.push(a[j]);
					tot[a[j]]++;
				}
				else
				{
					while(q.top()!=a[j])
					{
						tot[q.top()]=0;
						q.pop();
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				ans[i]+=tot[i];
			}
			for(int j=1;j<=m;j++)
			{
				tot[j]=0;
			}
			
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<" ";
		}
	
	return 0;
}

