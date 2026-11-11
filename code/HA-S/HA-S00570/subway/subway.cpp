#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ms(A,b) memset(A,b,sizeof A)
#define w while
using namespace std;
const int N=5e5+300;
int c;
int n,m,d,q;
int A[N];
ll dis[600][600];
ll qu[600][600];
bool vis[600];
vector<pair<int,ll>> son[N];
vector<pair<int,ll>> son1[N];
priority_queue<pair<ll,int>> q1;
void add(int a,int b,ll c) {son[a].push_back({b,c});}
void add1(int a,int b,ll c) {son1[a].push_back({b,c});son1[b].push_back({a,c});}
void dij(int s)
{
	for(int i=1;i<=n;i++) dis[s][i]=0x3f3f3f3f3f3f3f3f;
	ms(vis,0);
	q1.push({0,s});
	dis[s][s]=0;
	w(q1.size())
	{
		auto a=q1.top();
		q1.pop();
		int x=a.second;
		if(vis[x]) continue;
		vis[x]=1;
		for(auto t:son1[x])
			if(dis[s][t.first]>dis[s][x]+t.second)
				dis[s][t.first]=dis[s][x]+t.second,q1.push({-dis[s][t.first],t.first});
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>A[i];
	int k;
	int a,b;
	for(int i=1;i<=n;++i)
	{
		cin>>k;
		for(int j=1;j<=k;++j) cin>>a>>b,add(a,i,b);
	}
	ms(qu,0x3f);
	for(int i=1;i<=m;++i)
		for(int j=0;j<son[i].size();++j)
			for(int k=j+1;k<son[i].size();++k)
			{
				qu[son[i][j].first][son[i][k].first]=min(qu[son[i][j].first][son[i][k].first],son[i][j].second+son[i][k].second);
				qu[son[i][k].first][son[i][j].first]=min(qu[son[i][k].first][son[i][j].first],son[i][j].second+son[i][k].second);
			}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(qu[i][j]!=0x3f3f3f3f3f3f3f3f) add1(i,j,qu[i][j]);
	for(int i=1;i<=n;i++) dij(i);
	w(q--)
	{
		cin>>a>>b;
		ll minn=0x3f3f3f3f3f3f3f3f;
		for(auto t1:son[a])
			for(auto t2:son[b]) minn=min(minn,t1.second+t2.second+dis[t1.first][t2.first]+A[a]+A[b]);
		cout<<minn<<"\n";
	}
	return 0;
}
