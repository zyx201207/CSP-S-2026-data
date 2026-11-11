#include<bits/stdc++.h>

using namespace std;

struct node
{
	int to;
	long long value;
};

vector<node> road[100010];
int point[100010];
long long t[100010];
long long dis[100010];
bool vis[100010];
queue<int> Q;
long long a[100010];

int c,n,m,d,q;

void spfa(int s)
{
	int i;
	for(i=0;i<=n;i++)
	{
		dis[i]=1e18;
		vis[i]=false;
	}
	Q.push(s);
	vis[s]=true;
	dis[s]=0;
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		vis[x]=false;
		for(i=0;i<road[x].size();i++)
		{
			if(dis[road[x][i].to]>dis[x]+road[x][i].value)
			{
				dis[road[x][i].to]=dis[x]+road[x][i].value;
				if(vis[road[x][i].to]==false)
				{
					Q.push(road[x][i].to);
					vis[road[x][i].to]=true;
				}
			}
		}
	}
}

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	int i,j,k;
	int x;
	node tmp;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<m;i++)
	{
		cin>>x;
		for(j=0;j<x;j++)
		{
			cin>>point[j];
			cin>>t[point[j]];
			for(k=0;k<j;k++)
			{
				tmp.to=point[k];
				tmp.value=t[point[j]]+t[point[k]];
				road[point[j]].push_back(tmp);
				tmp.to=point[j];
				road[point[k]].push_back(tmp);
			}
		}
	}
	for(i=0;i<q;i++)
	{
		cin>>j>>k;
		spfa(j);
		cout<<(a[j]+a[k]+dis[k])<<endl;
	}

	return 0;
}
