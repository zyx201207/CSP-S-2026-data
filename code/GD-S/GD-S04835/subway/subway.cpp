#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 505,MAXM = 500005;
const int INF = 0x3f3f3f3f;
int w[MAXM];
struct at{
	int a,t;
};
vector<int> has[MAXM];
vector<at> to[MAXN];
int dist[MAXM];
int c,n,m,d,q;
int  dij1(int x,int y)
{
	for(int i = 1;i <= m;i++)
		dist[i] = INF;
	dist[x] = w[x];
	priority_queue<pair<int,int>> q;
	q.push({dist[x],x});
	while(!q.empty())
	{
		int di = q.top().first;
		int front = q.top().second;
		q.pop();
		for(int line:has[front])
		{
			int down = 0;
			for(at i : to[line])
				if(i.a == front)
				{
					down = i.t;
					break;
				}
			for(at i : to[line])
			{
				if(i.a == front) continue;
				int dd = down+i.t;
				if(dist[front] + dd < dist[i.a])
				{
					dist[i.a] = dist[front]+dd;
					q.push({dist[i.a],i.a});
				}
			}
		}
	}
	return dist[y]+w[y];
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	cin>>c>>n>>m>>d>>q;
	
	for(int i = 1;i <= m;i++)
		scanf("%d",&w[i]);
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			to[i].push_back({x,y});
			has[x].push_back(i);
		}
	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",dij1(x,y));
	}
	return 0;
 } 
 /*
	if(c >= 7 && c <=11)
	{
		for(int i = 1;i <= m;i++)
			scanf("%d",&w[i]);
		for(int i = 1;i <= m;i++)
			for(int j = 1;j <= m;j++)
				if(i == j) A_g[i][j] = 0;
				else A_g[i][j] = INF;
		for(int i = 1;i <= n;i++)
		{
			int k;
			cin>>k;
			int a1,t1,a2,t2;
			cin>>a1>>t1>>a2>>t2;
			A_g[a1][a2] = A_g[a2][a1] = t1+t2;
		}
		for(int k = 1;k <= m;k++)
		{
			for(int i = 1;i <= m;i++)
			{
				for(int j = 1;j <= m;j++)
				{
					A_g[i][j] = A_g[i][k]+A_g[k][j];
				}
			}
		}
		while(q--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",A_g[x][y]);
		}
		return 0;
	}
	*/
