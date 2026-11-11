#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=300005;
int n,m,a[N],ans[M];
bool vis[M];
stack<int>q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==1)
			{
				while(q.top()!=a[j])
				{
					ans[q.top()]--;
					vis[q.top()]=0;
					q.pop();
				}
				ans[q.top()]--;
				vis[q.top()]=0;
				q.pop();
			}
			q.push(a[j]);
			ans[a[j]]++;
			vis[a[j]]=1;
		}
		while(!q.empty())q.pop();
//		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
//			cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
