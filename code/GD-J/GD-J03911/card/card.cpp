#include<bits/stdc++.h>
using namespace std;
long long n,m,a[550000],b[550000],c[550000],ans[550000],cnt;
bool vis[550000];
stack<int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(!vis[a[j]])
			{
				s.push(a[j]);
				vis[a[j]]=true;
			}	
			else
			{
				while(!s.empty()&&s.top()!=a[j])
				{
					vis[s.top()]=false;
					s.pop();
				}	
			}
		}
		while(!s.empty())
		{
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
