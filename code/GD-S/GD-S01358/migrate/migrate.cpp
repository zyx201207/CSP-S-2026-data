#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 10;
const int INF = 0x3f3f3f3f;
int n;
ll a[N],d,b[N],ans,vis[N];
void dfs(int u,int s)
{
	for(int i=n;i>u;i--)
	{
		if(a[i]-a[u]<=d)
		{
			if(b[i]==b[u]+1)
			{
				vis[i]^=1;
			}
			if(b[i]>b[u]+1)
			{
				b[i]=b[u]+1;
				dfs(i,s);
			}
		}
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i]=INF;
		}
		for(int j=1;j<=n;j++)
		{
			b[j]=0;
			dfs(j,j);
			for(int i=j+1;i<=n;i++)
			{
				b[i]=INF;
				if(vis[i])
				{
					ans++;
				}
				vis[i]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

