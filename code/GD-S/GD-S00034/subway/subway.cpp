#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过
long long w[500005];
int k[500005];
long long ans;
vector<int>a[500005];
int st,en; 
int t[505][500005];
bool b[505][500005];
inline void dfs(long long sum,int now,int fa,int num)
{
	//cout<<now<<" ";
	if(now==en)
	{
		ans=min(ans,sum);
		return ;
	}
	for(auto i:a[now])
	{
		
		if(i!=fa)
		{			
			if(b[num][i]!=0)
			{
				dfs(sum+t[now][i],i,now,i);
			}
			for(int j=1;j<=n;j++)
			{
				if(j!=num&&b[j][i]==1&&b[j][now]==1)
				{
					int sum2=sum+t[now][i]+t[now][now];
					dfs(sum2,i,now,i);
				}
			}	
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		int last=0;
		for(int j=1;j<=k[i];j++)
		{
			int now;
			scanf("%d%d",&now,&t[i][j]);
			
			if(last!=0)
			{
				a[last].push_back(now);
				a[now].push_back(last);		
			}
			last=now;
			b[i][now]=1;
		}
	}	
	for(int e=1;e<=q;e++)
	{
		scanf("%d%d",&st,&en);
		ans=1e18;
		for(int i=1;i<=n;i++)
		{
			if(b[i][st]==1)
			{
				dfs(t[st][st],i,st,i);
			}
		}
		ans+=w[st]+w[en];
		printf("%lld\n",ans);
	}
	return 0;
}
