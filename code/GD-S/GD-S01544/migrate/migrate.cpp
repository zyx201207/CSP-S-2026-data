#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,d;
const int N=1e5+5;
int dis[N],s,cnt,minn;
void dfs(int st,int ed,int step)
{
	if(st==ed)
	{
		if(step==minn) cnt++;
		else
		{
			if(step<minn)
			{
				minn=step;
				cnt=0;
			}
		}
	}
	for(int i=st+1;i<=ed;i++)
	{
		if(dis[i]-dis[st]<=d)
		{
			dfs(i,ed,step+dis[i]-dis[st]);
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++) scanf("%d",&dis[i]);
		for(int i=1;i<=n;i++)
		{
			minn=INT_MAX;
			cnt=0;
			for(int j=i+1;j<=n;j++)
			{
				minn=INT_MAX;
				dfs(i,j,0);
				if(minn!=INT_MAX&&cnt==2)
				{
					s++;
				}
			}
		}
		printf("%d\n",s);
		s=0;
	}
	return 0;
}
