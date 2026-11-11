#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n,m;
int q[500005];
int vis[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>q[i];
	for(int i=1;i<=n;i++) 
	{
		vis[q[i]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<vis[i]<<" ";
	}
	return 0;
} 
