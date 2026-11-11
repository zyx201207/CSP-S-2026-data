#include<bits/stdc++.h>

using namespace std;

int c,n,m,d,q,w[1000],k[1000][1000],t[1000][1000],x,y,mapp[1000][1000],record[1000][1000],ans = 0x3f3f3f3f3f;

void dfs(int step,int now)
{
	if(now == y)
	{
		ans = min(ans,step);
		return;
	}
	for(int i = 1;i<=m;i++)
	{
		if(mapp[now][i]!=0&&record[now][i] == 0)
		{
			record[now][i] = 1;
			record[i][now] = 1;
			dfs(step+t[mapp[now][i]][now]+t[mapp[now][i]][i],i);
			record[now][i] = 0;
			record[i][now] = 0;
		}
	}
}


int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++)
	{
		cin>>k[i][0];
		for(int j = 1;j<=k[i][0];j++)
		{
			cin>>k[i][j];
			cin>>t[i][k[i][j]];
		}
	}
	for(int i = 1;i<=n;i++)
	{
		mapp[k[i][1]][k[i][2]] = i;
		mapp[k[i][2]][k[i][1]] = i;
	 } 
	while(q--)
	{
		ans = 0x3f3f3f3f3f3f3f;
		cin>>x>>y;
		dfs(w[x]+w[y],x);
		cout<<ans<<endl;
	}
	
} 
