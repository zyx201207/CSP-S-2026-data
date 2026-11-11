#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2e5+10;
int n,m;
int a[N];
int b[N];
int ans[N];
bool vis[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int qq=1;qq<=n;qq++)
	{
		memset(b,0,sizeof b);
		memset(vis,0,sizeof vis);
		int t=0;
		for(int i=qq;i<=n;i++)
		{
			if(vis[a[i]]==0)b[++t]=a[i],vis[a[i]]=1;
			else
			{
				bool flag=0;
				int x=0;
				for(int j=1;j<=t;j++)
				{
					if(flag)
					{
						vis[b[j]]=0;
					}
					if(b[j]==a[i])flag=1,x=j;
				}
				t=x;
			}	
		}
		for(int i=1;i<=t;i++)if(vis[b[i]]==1)ans[b[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
