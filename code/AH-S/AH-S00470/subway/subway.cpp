# include <bits/stdc++.h>
using namespace std;
using LL=long long;
using PLL=pair<LL,LL>;
const int N=5e5+10;
LL n,m,d,q,c;
LL w[N];
vector<PLL> g[N];
LL dis[N];
bool st[N];
int S,T;
map<PLL,LL> dd;
void SPFA()
{
	memset(dis,0x3f,sizeof(dis));
	memset(st,0,sizeof(st));
	dis[S]=0;
	st[S]=1;
	queue<LL> q;
	q.push(S);
	while(q.size())
	{
		LL tmp=q.front();
		st[tmp]=0;
		q.pop();
		for(auto x:g[tmp])
		{
			int to=x.first,w=x.second;
			if(dis[to]>dis[tmp]+w)
			{
				dis[to]=dis[tmp]+w;
				if(!st[to])
				{
					q.push(to);
					st[to]=1;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		dd[{S,i}]=dis[i]+w[S]+w[i];
	}
	return;
}	
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		LL zt[k+10],t[k+10];
		for(int j=1;j<=k;j++)
		{
			cin>>zt[j]>>t[j];
		}
		for(int j=1;j<=k-1;j++)
		{
			for(int x=j+1;x<=k;x++)
			{
				PLL tmp1,tmp2;
				tmp1.first=zt[x];
				tmp1.second=(t[j]*1LL+t[x]*1LL)*1LL;
				tmp2.first=zt[j];
				tmp2.second=(t[j]*1LL+t[x]*1LL)*1LL;
				g[zt[j]].push_back(tmp1);
				g[zt[x]].push_back(tmp2);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>S>>T;
		if(dd.count({S,T})) cout<<dd[{S,T}]<<"\n";
		else
		{
			SPFA();
			cout<<dis[T]+w[S]+w[T]<<"\n";
		}
	}
	return 0;
}
