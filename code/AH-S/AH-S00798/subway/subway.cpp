#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
}b[505][1005];
int c,n,m,d,p,k,st,en,minn=INT_MAX,a[1005],e[1005],flag[505][1005],tmp[505];
void dfs(int x,int sum)
{
	if(x==en)
	{
		minn=min(minn,sum+a[en]);
		return ;
	}
	if(sum>minn) return ;
	for(int i=1;i<=n;i++)
	{
		if(flag[i][x]==0||tmp[i]==0) continue;
		else 
		{
			for(int j=1;j<=e[i];j++)
				if(b[i][j].x!=x)
				{
					tmp[i]=0;
					dfs(b[i][j].x,sum+b[i][flag[i][x]].y+b[i][j].y);
					tmp[i]=1;
				}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>e[i];
		for(int j=1;j<=e[i];j++)
		{
			cin>>b[i][j].x>>b[i][j].y;
			flag[i][b[i][j].x]=j;
		}
	}
	while(p--)
	{
		minn=INT_MAX;
		memset(tmp,1,sizeof tmp);
		cin>>st>>en;
		dfs(st,a[st]);
		cout<<minn<<endl;
	}
	return 0;
}
