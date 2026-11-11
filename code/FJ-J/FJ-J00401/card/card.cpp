#include <bits/stdc++.h>
using namespace std;
const int N=1e5*2+10;
int n,m;
int a[N];
int v[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(v,0,sizeof(v));
	bool vis[N];
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{	
		queue<int> q;
		memset(vis,false,sizeof(vis));
		for(int j=i;j<=n;j++)//´òÅÆ 
		{
			//q.push(a[j]);
			if(vis[a[j]]==true)
			{
				q.pop();
				int u=q.front();
				while(u!=a[j] && !q.empty())
				{
					u=q.front();
					q.pop();
				}
			}
			q.push(a[j]);
			vis[a[j]]=true;
		}
		while(!q.empty())
		{
			int u=q.front();q.pop();
			v[u]++;
		}
//		for(int i=1;i<=m;i++)
//		{
//			printf("%d ",v[i]);
//		}
//		printf("\n");
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",v[i]);
	}
	return 0;
}
