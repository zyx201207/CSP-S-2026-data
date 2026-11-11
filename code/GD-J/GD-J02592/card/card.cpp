#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[500005];
bool vis[500005];
stack<int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]])
			{
				while(!s.empty()&&s.top()!=a[j])
				{
					vis[s.top()]=false;
					s.pop();
				}
				s.pop();
				vis[a[j]]=false;
			}
			s.push(a[j]);
			vis[a[j]]=true;
		}
		for(int j=1;j<=m;j++) cnt[j]+=vis[j];
		while(!s.empty()) s.pop();
		memset(vis,false,sizeof(vis));
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
