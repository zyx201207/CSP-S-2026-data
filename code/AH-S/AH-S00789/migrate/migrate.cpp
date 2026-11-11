#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[305],ans,cnt[305],vis[305],mn[305];
vector<long long> v[305];
void dfs(long long w,long long len)
{
	if (len<mn[w])
	{
		mn[w]=len;
		cnt[w]=1;
	}
	else if (len==mn[w])
	{
		cnt[w]++;
	}
	for (int i=0;i<v[w].size();i++)
	{
		if (!vis[v[w][i]])
		{
			vis[v[w][i]]=1;
			dfs(v[w][i],len+1);
			vis[v[w][i]]=0;
		}		
	} 
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	c=1;
	if (c>=1&&c<=6)
	{
		while(t--)
		{
			cin>>n>>d;
			for (int i=1;i<=n;i++)
			{
				cin>>x[i];
				v[i].clear();
			}
			for (int i=1;i<=n;i++)
			{
				for (int j=i+1;j<=n;j++)
				{
					if (abs(x[i]-x[j])<=d)
					{
						v[i].push_back(j);
						v[j].push_back(i);
					}
				}
			} 
			ans=0;
			for (int i=1;i<=n;i++)
			{
				memset(cnt,0,sizeof(cnt));
				memset(vis,0,sizeof(vis));
				for (int j=1;j<=n;j++)
				{
					mn[j]=1e9;
				}
				mn[i]=0;
				vis[i]=1;
				dfs(i,0);
				for (int j=1;j<=n;j++)
				{
					if (cnt[j]==2)
					{
						ans++;
					}
				}
			}
			cout<<ans/2<<"\n";
		}
		return 0;
	}
	return 0;
} 
