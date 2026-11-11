#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long long c,n,m,d,q,w[500005],a[50005],t[50005],k,sumk=0,dis[5000005];
bool vis[5000005];
struct node{
	long long v,w;
};
bool operator<(node x,node y){return x.w>y.w;}
vector<node> p[5000005];//zhanting:1~m   zhantai:m+quanxianluhao
long long dijsktra(long long st,long long en)
{
	priority_queue<node> q;
	for(int i=1;i<=5000000;i++)
	{
		dis[i]=1e9+5;
		vis[i]=0;
	} 
	q.push({st,0});
	dis[st]=0;
	while(!q.empty())
	{
		int x=q.top().v;
		q.pop();
		if(vis[x]==1) continue;
		vis[x]=1;
		int len=p[x].size();
		for(int i=0;i<len;i++)
		{
			node xx=p[x][i];
			if(dis[x]+xx.w<dis[xx.v])
			{
				dis[xx.v]=dis[x]+xx.w;
				q.push({xx.v,dis[xx.v]});
			}
		}
	}
	return dis[en];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c>15)
	{
		cout<<"Shu3Dao4Nan2!Nan2Yu2Shang4Qing1Tian1!";
		return 0;
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
			p[a[j]].push_back({m+sumk+j,t[j]});
			p[m+sumk+j].push_back({a[j],t[j]});
			if(j!=1)
			{
				p[m+sumk+j].push_back({m+sumk+j-1,0});
				p[m+sumk+j-1].push_back({m+sumk+j,0});
			}
		}
		p[m+sumk+1].push_back({m+sumk+k,0});
		p[m+sumk+k].push_back({m+sumk+1,0});
		sumk+=k;
	}
	while(q--)
	{
		int st,en;
		cin>>st>>en;
		cout<<dijsktra(st,en)+w[st]+w[en]<<'\n';
	}
	return 0;
}
