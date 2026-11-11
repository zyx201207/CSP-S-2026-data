#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
#define int long long
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int dis[N];//1 --> nµØÌú¿Ú£¬n + 1 --> 2nÕ¾Ìü 
vector<pair<int,int> >vc[N]; 
bool vis[N];
queue<int>q;
int c,n,m,d,qu;
void spfa(int st)
{
	memset(dis,INF,sizeof(dis));
	dis[st] = 0;
	q.push(st);
	vis[st] = 1;
	while(!q.empty())
	{
		int top = q.front();
		q.pop();
		vis[top] = 0;
		for(int i = 0;i < vc[top].size();i++)
		{
			int to = vc[top][i].first,w = vc[top][i].second;
			if(dis[to] > dis[top] + w)
			{
				dis[to] = dis[top] + w;
				if(!vis[to])
				{
					vis[to] = 1;
					q.push(to);
				}
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> qu;
	for(int i = 1;i <= m;i++)
	{
		int wzhan;
		scanf("%lld",&wzhan);
		vc[i].push_back(make_pair(m + i,wzhan));
		vc[m + i].push_back(make_pair(i,wzhan));
	}
	int len = 2 * m;
	for(int i = 1;i <= n;i++)
	{
		int k,last;
		scanf("%lld",&k);
		for(int j = 1;j <= k;j++)
		{
			int wxi,di;
			scanf("%lld%lld",&di,&wxi);
			vc[++len].push_back(make_pair(m + di,wxi));
			vc[m + di].push_back(make_pair(len,wxi));
			if(j == 1)
			{
				last = di;
				continue;
			}
			vc[len].push_back(make_pair(len - 1,0));
			vc[len - 1].push_back(make_pair(len,0));
		}
	}
	/*for(int i = m + 1;i <= 2 * m;i++)
	{
		for(int j = 0;j < vc[i].size();j++)
			cout << vc[i][j].first << " ";
		cout << endl;
	}*/
	for(int i = 1;i <= qu;i++)
	{
		int st,en;
		scanf("%lld%lld",&st,&en);
		spfa(st);
		printf("%lld\n",dis[en]); 
	}
	return 0;
}

