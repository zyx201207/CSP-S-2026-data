#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],vis[300005];
stack<int> desk; 
inline void clear()
{
	while(!desk.empty()){
		desk.pop();
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	desk.push(a[1]);
	vis[a[1]]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
//			clear();
			if(vis[a[j]])
			{
				while(desk.top()!=a[j])
				{
					vis[desk.top()]=0;
					desk.pop();
				}
//				desk.push(a[i]);
//				vis[a[i]]=1;
			}
			else
			{
				desk.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!desk.empty())
		{
			ans[desk.top()]++;
			desk.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i];
	}
	return 0;
}


