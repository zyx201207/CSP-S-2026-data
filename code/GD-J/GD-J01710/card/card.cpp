#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int INF=0x3f3f3f3f;
int n,m,a[N],ans[N],vis[N];
bool flag[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int t=1;t<=n;t++)
	{
		memset(vis,0,sizeof(vis));
		memset(flag,0,sizeof(flag));
		for(int i=t;i<=n;i++)
		{
			ans[a[i]]++;
			if(vis[a[i]])
			{
				for(int j=i-1;j>=t;j--)
				{
					if(flag[j])
						continue;
					else
					{
					flag[j]=1;
					ans[a[j]]--;
					if(a[j]==a[i])
						break;
					}
				}
			}
			else
				vis[a[i]]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
 return 0;
}

