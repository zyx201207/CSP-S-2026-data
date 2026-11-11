#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],vis[300005],iss[300005];
stack<int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++)
	{
		memset(iss,0,sizeof(iss));
		memset(vis,0,sizeof(vis));
		for(int i=k;i<=n;i++)
		{
			if(vis[a[i]])
			{
				while(s.top()!=a[i])
				{
					vis[s.top()]=0;
					s.pop();
				}
				vis[a[i]]=0;
				s.pop();
			}
			s.push(a[i]);
			vis[a[i]]=1;
		}
		while(!s.empty())
		{
			iss[s.top()]=1;
			s.pop();
		}
		for(int i=1;i<=m;i++) ans[i]+=iss[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
