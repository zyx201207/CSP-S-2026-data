#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[505][200005],t[505][200005],x,y,k[505];
struct node
{
	int time;
	int line;	
}mapp[5005][5005];
void bfs()
{
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==j) continue;
			for(int k=1;k<=m;k++)
			{
				if(mapp[i][j].time==0&&mapp[i][k].time!=0&&mapp[k][j].time!=0)
					mapp[i][j].time=mapp[i][k].time+mapp[k][j].time-w[k]-w[k]; 
				else if(mapp[i][k].time!=0&&mapp[k][j].time!=0&&mapp[i][j].time>mapp[i][k].time+mapp[k][j].time-w[k]-w[k])
					mapp[i][j].time=mapp[i][k].time+mapp[k][j].time-w[k]-w[k];
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
		cin >> w[i];
	for(int i=1;i<=n;i++)
	{
		cin >> k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
		for(int j=1;j<=k[i]-1;j++)
		{
			for(int p=1;p<=k[i]-j;p++){
			mapp[a[i][j]][a[i][j+p]].line=i;
			mapp[a[i][j+p]][a[i][j]].line=i;
			mapp[a[i][j]][a[i][j+p]].time=w[a[i][j]]+t[i][j]+t[i][j+p]+w[a[i][j+p]];
			mapp[a[i][j+p]][a[i][j]].time=w[a[i][j]]+t[i][j]+t[i][j+p]+w[a[i][j+p]];
			}
		}
	}
	bfs();
	while(q--)
	{
		cin >> x >> y;
		cout << mapp[x][y].time << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
