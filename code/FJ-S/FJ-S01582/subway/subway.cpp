#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using pii=pair<int,int>;
int w[500010],d[500010],t[500010],x[500010];
bool st[500100];
vector<pii> v[500010];
int a[3][500010];
int b[500010];
void dijistar(int x)
{
	memset(d,INF,sizeof d);
	memset(st,false,sizeof st);
	priority_queue<pii,vector<pii>,greater<>> q;
	d[x]=0;
	q.push({0,x});
	while(!q.empty())
	{
		auto f=q.top().second;
		q.pop();
		if(st[f]) continue;
		st[f]=1;
		for(auto i:v[f])
		{
			if(d[i.first]>d[f]+i.second)
			{
				d[i.first]=d[f]+i.second;
				q.push({d[i.first],i.first});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,p,q;
	cin>>c>>n>>m>>p>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(n==1)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			int x;
			cin>>x;
			cin>>b[x];
		}
		while(q--)
		{
			int xx,yy;
			cin>>xx>>yy;
			cout<<b[xx]+b[yy]+w[xx]+w[yy];
		}
		return 0;
	}
	if(n==2)
	{
		int k1;
		cin>>k1;
		for(int i=1;i<=k1;i++)
		{
			int x;
			cin>>x;
			cin>>a[1][x];
			st[x]=1;
		}
		int k2;
		cin>>k2;
		int mi=INF;
		for(int i=1;i<=k2;i++)
		{
			int x;
			cin>>x;
			cin>>a[2][x];
			if(st[x]) mi=min(mi,a[1][x]+a[2][x]);
		}
		while(q--)
		{
			int xx,yy;
			cin>>xx>>yy;
			if(a[1][xx]!=0&&a[1][yy]!=0)
			{
				cout<<a[1][xx]+a[1][yy]+w[xx]+w[yy]<<endl;
				continue; 
			}
			if(a[2][xx]!=0&&a[2][yy]!=0)
			{
				cout<<a[2][xx]+a[2][yy]+w[xx]+w[yy]<<endl;
				continue;
			}
			if(a[1][xx]!=0) cout<<a[1][xx]+a[2][yy]+w[xx]+w[yy]+mi<<endl;
			else cout<<a[2][xx]+a[1][yy]+w[xx]+w[yy]+mi<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>x[j]>>t[j];
		for(int j=1;j<=k;j++)
		{
			for(int q=j+1;q<=k;q++)
			{
				v[x[j]].push_back({x[q],t[j]+t[q]});
				v[x[q]].push_back({x[j],t[j]+t[q]});
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		dijistar(x);
		cout<<d[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
