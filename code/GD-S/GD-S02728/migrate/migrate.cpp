#include<bits/stdc++.h>
using namespace std;
int _,text;
int n,ans;
long long d;
long long a[2000005];
vector<int> b[2000005];
int dist[2000005];
bool vis[2000005];
void di(int x)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,x});
	for(int i=1;i<=n;i++)
	{
		dist[i]=0x6f6f6f6f;
		vis[i]=0;
	}
	dist[x]=0;
	vis[x]=1;
	while(!pq.empty())
	{
		int pos=pq.top().second;
		pq.pop();
		vis[x]=0;
		for(int i=0;i<b[pos].size();i++)
		{
			int npos=b[pos][i];
			if(dist[npos]>dist[pos]+1)
			{
				dist[npos]=dist[pos]+1;
				if(!vis[npos])
				{
					pq.push({dist[npos],npos});
					vis[npos]=1;
				}
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>_>>text;
	while(text--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		cout<<rand()%n<<"\n";
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
