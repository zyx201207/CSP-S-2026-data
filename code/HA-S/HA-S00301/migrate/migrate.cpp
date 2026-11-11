#include<bits/stdc++.h>

#define ll long long

using namespace std;

const ll N=2e6+10;

struct A
{
	int wi;
	ll z;
	int num;
	bool operator<(const A &s)const
	{
		return s.z<z;
	}
}a[N];

int c,T;
int n;
ll d;
ll x[N];
bool bo[N];
int u,v;
ll co;
int num;

vector<int> ve[N];
priority_queue<A> q;

void dijkstra(int k)
{
	while(!q.empty())
	{
		q.pop();
	}
	for(int i = k;i<=n;i++)
	{
		bo[i]=0;
		a[i].z=INT_MAX;
	}
	a[k].z=0;
	num=0;
	q.emplace(a[k]);
	while(!q.empty())
	{
		if(num==n-k+1)
		{
			return;
		}
		u=q.top().wi;
		q.pop();
		if(bo[u])
		{
			continue;
		}
		if(a[u].num==2)
		{
			co++;
		}
		bo[u]=1;
		num++;
		for(int i = 0;i<ve[u].size();i++)
		{
			v=ve[u][i];
			if(bo[v])
			{
				continue;
			}
			if(a[u].z+1<a[v].z)
			{
				a[v].z=a[u].z+1;
				a[v].num=1;
			}
			else if(a[u].z+1==a[v].z)
			{
				a[v].num++;
			}
			q.emplace(a[v]);
		}
	}
}

ll Q()
{
	co=0;
	cin>>n>>d;
	for(int i = 1;i<=n;i++)
	{
		a[i].wi=i;
		ve[i].clear();
		cin>>x[i];
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = i+1;j<=n;j++)
		{
			if(x[j]-x[i]<=d)
			{
				ve[i].emplace_back(j);
			}
		}
	}
	for(int i = 1;i<=n;i++)
	{
		dijkstra(i);
	}
	return co;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cout<<Q()<<"\n";
	}
	return 0;
}
