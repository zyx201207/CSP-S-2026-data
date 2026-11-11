#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int ss,ee;
int w[500005];
int e[50005][50005];
int dis[500005];
void bfs()
{
	queue<int> p;
	p.push(ss);
	
	while(!p.empty())
	{
		int h=p.front();
		p.pop();
		for(int i=1;i<=m;i+=2)
		{
			int y=e[h][i],z=e[h][i+1];
			if(dis[y]>dis[h]+z)
			{
				dis[y]=dis[h]+z;
				p.push(y);
			}
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k+k;j++)
		{
			cin>>e[i][j]>>e[i][j+1];
		}
	}
	for(int i=1;i<=q;i++)
	{
		memset(dis,0x3f,sizeof dis);
		cin>>ss>>ee;
		bfs();
		cout<<dis[ee]<<endl;
	}
	return 0;
}

