#include <bits/stdc++.h>
#define O 20005
using namespace std;
int c,n,m,d,Q;
int w[O],mp[505][O],pos[O][505];
vector <int> line[505];
vector <int> vis[O];
priority_queue <pair<int,pair<int,int> > ,vector <pair<int,pair<int,int> > > ,greater<pair<int,pair<int,int> > > > q;
void bfs(int idx,int lyr)
{
	
	mp[lyr][idx] = 0;
	q.push({0,{lyr,idx}});
	while(!q.empty())
	{
		pair<int,pair<int,int> > f = q.top();
		q.pop();
		int val = f.first,l = f.second.first,ps = f.second.second;
		for(int i = 0;i < line[l].size();++i)	//同一条线路上的,一下一上 
		{
			if(mp[l][line[l][i]] > val + pos[line[l][i]][l] + pos[ps][l])
			{
				mp[l][line[l][i]] = val + pos[line[l][i]][l] + pos[ps][l];
				q.push({mp[l][line[l][i]],{lyr,line[l][i]}});
			}
		}
		for(int i = 0;i < vis[ps].size();++i)
		{
			if(vis[ps][i] == l)
				continue;
			if(mp[vis[ps][i]][ps] > val)
			{
				q.push({val,{vis[ps][i],ps}});
				mp[vis[ps][i]][ps] = val;
			}
				
		} 
	}
//	return 0;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&Q);
	for(int i = 1;i <= m;++i)
		scanf("%d",&w[i]);
	for(int i = 1;i <= n;++i)
	{
		int p;
		scanf("%d",&p);
		while(p--)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			line[i].push_back(x);
			vis[x].push_back(i);
			pos[x][i] = y;			
		}

	}
	for(int i = 1;i <= Q;++i)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		int ans = INT_MAX;
		memset(mp,0x3f,sizeof(mp));
		for(int k = 0;k < vis[x].size();++k)
		{
//			cout << "Run" << endl;
			bfs(x,vis[x][k]);
			for(int t = 0;t < vis[y].size();++t)
				ans = min(ans,mp[vis[y][t]][y]);
		}
		printf("%d\n",ans + w[x] + w[y]);
	}
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
