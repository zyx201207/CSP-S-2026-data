#include<bits/stdc++.h>

#define ll long long
#define fi first
#define se second

using namespace std;

const ll N=5e5+10;

struct A
{
	int wi;
	ll z;
	bool operator<(const A &s)const
	{
		return s.z<z;
	}
}a[N];

int c,n,m,d,q;
int k;
int b[N];
ll ti[N];
ll val[N];
int num;
int x,y;
bool bo[N];
int u,v;
ll w;

map<pair<int,int>,bool> mp;

vector<pair<int,ll>> ve[N];

priority_queue<A> qu;

void dijkstra(int s,int t)
{
	for(int i = 1;i<=m;i++)
	{
		a[i].z=INT_MAX;
		bo[i]=0;
	}
	a[s].z=0;
	while(!qu.empty())
	{
		qu.pop();
	}
	qu.emplace(a[s]);
	while(!qu.empty())
	{
		u=qu.top().wi;
		qu.pop();
		if(u==t)
		{
			return;
		}
		if(bo[u])
		{
			continue;
		}
		bo[u]=1;
		for(int i = 0;i<ve[u].size();i++)
		{
			v=ve[u][i].fi;
			w=ve[u][i].se;
			if(bo[v])
			{
				continue;
			}
			a[v].z=min(a[v].z,a[u].z+w);
			qu.emplace(a[v]);
		}
	} 
	return;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
	{
		a[i].wi=i;
		cin>>val[i];
	}
	for(int i = 0;i<n;i++)
	{
		cin>>k;
		for(int j = 1;j<=k;j++)
		{
			cin>>b[j]>>ti[j];
		}
		for(int j =1;j<=k;j++)
		{
			for(int in = j+1;in<=k;in++)
			{
				ve[b[j]].emplace_back(b[in],ti[j]+ti[in]);
				ve[b[in]].emplace_back(b[j],ti[j]+ti[in]);
			}
		}
	}
//	cout<<"11111111111"<<"\n";
//	for(int i = 1;i<=m;i++)
//	{
//		for(int j = 0;j<ve[i].size();j++)
//		{
//			cout<<i<<" "<<ve[i][j].fi<<" "<<ve[i][j].se<<"\n";
//		}
//	}
	while(q--)
	{
		cin>>x>>y;
		dijkstra(x,y);
		cout<<val[x]+val[y]+a[y].z<<"\n";
	}
	return 0;
}
