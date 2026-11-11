#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,flag,w[500005],a[505][500005],t[505][500005],x[100005],y[100005],dis[500005],book[500005],k[505];
struct Node
{
	int idx,val;
};
vector <Node> v[500005];
queue <Node> q1;
void dijkstra(Node num)
{
	memset(dis,0x3f,sizeof(dis));
	memset(book,0x3f,sizeof(book));
	dis[num.val]=0;
	q1.push(num);
	book[num.val]=1;
	while(!q1.empty())
	{
		Node f=q1.front();
		for(int i=0;i<v[f.val].size();i++)
		{
			if(book[v[f.val][i].val]==0)
			{
				book[v[f.val][i].val]=1;
				q1.push(v[f.val][i]);
			}
			if(v[f.val][i].idx==v[f.val][0].idx) dis[f.val]=0;
			else
			{
				dis[f.val]=min(dis[f.val],t[v[f.val][0].idx][v[f.val][0].val]+t[v[f.val][i].idx][v[f.val][i].val]);
			}
		}
		q1.pop();
		book[num.val]=0;
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			v[a[i][j]].push_back({i,a[i][j]});
			if(j!=1)
			{
				v[a[i][j]].push_back({i,a[i][j-1]});
				v[a[i][j-1]].push_back({i,a[i][j]});
			}
		}
	}
	for(int e=1;e<=q;e++)
	{
		cin>>x[e]>>y[e];
		for(int i=1;i<=n;i++)
		{
			flag=0;
			for(int j=1;j<=k[i];j++)
			{
				if(a[i][j]==x[e]||a[i][j]==y[e]) flag++;
				if(flag==2)
				{
					cout<<t[i][x[e]]+t[i][y[e]]+w[x[e]]+w[y[e]];
					break;
				}
			}
			if(flag==2) break;
		}
		if(flag==2) continue;
		dijkstra(v[x[e]][0]);
		cout<<dis[y[e]]+w[x[e]]+w[y[e]]<<endl;
	}
	return 0;
}
