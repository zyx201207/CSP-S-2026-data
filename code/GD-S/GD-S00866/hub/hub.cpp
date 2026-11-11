#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int N=5e5+10;
int c,t;
int n,k;
int dis[N];
vector<int> v[N];
int sum;
int b[N];
int tmp;
bool tool[N];
int count(int x)
{
	sum=0;
	while(x)
		sum+=x&1,x=x>>1;
	return sum;
}
bool vis[N];
int cnt;
int p[N][30];
int deep[N];
int ans;
int LCA;
void dfs1(int x)
{
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i]])
			dfs1(v[x][i]);
}
void dfs(int x,int fa)
{
	deep[x]=deep[fa]+1;
	p[x][0]=fa;
	for(int i=1;i<30;i++)
		p[x][i]=p[p[x][i-1]][i-1];
	for(int i=0;i<v[x].size();i++)
	{
		if(v[x][i]!=fa)
			dfs(v[x][i],x);
	}
}
int lca(int x,int y)
{
	if(deep[x]<deep[y])swap(x,y);
	for(int i=29;i>=0;i--)
		if(deep[p[x][i]]>=deep[y])
			x=p[x][i];
	if(x==y)return x;
	for(int i=29;i>=0;i--)
		if(p[x][i]!=p[y][i])
			x=p[x][i],y=p[y][i];
	return p[x][0];
}
int ans2;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1,x,y;i<n;i++)
		{
//			dis[i]=0;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		ans2=1e9;
		for(long long o=2;o<(1ll<<n);o++)
		{
			if(count(o)!=k)continue;
			tmp=0;
			for(int i=1;i<=n;i++)
			{
				if((o>>(i-1))&1)
					b[++tmp]=i,vis[i]=tool[i]=0;
				else
					vis[i]=tool[i]=1;
			}
			cnt=0;
			for(int i=1;i<=tmp;i++)
			{
				if(!vis[b[i]])dfs1(b[i]),cnt++;
				if(cnt>2)break;
			}
//			cout<<cnt;
			if(cnt>2)continue;
//			cout<<"b:";
//			for(int i=1;i<=tmp;i++)
//				cout<<b[i]<<' ';
//			cout<<'\n';
//			cout<<"sum:";
			for(int i=1;i<=n;i++)
			{
				if(!tool[i])continue;
				sum=1e9;
				for(int j=1;j<=tmp;j++)
				{
					LCA=lca(i,b[j]);
					if(LCA==i)sum=min(sum,deep[b[j]]-deep[i]);
					else if(LCA==b[j])sum=min(sum,deep[i]-deep[b[j]]);
					else sum=min(sum,deep[i]+deep[b[j]]-deep[lca(i,b[j])]);
//					cout<<i<<' '<<sum<<'\n';
				}
//				cout<<i<<' '<<sum<<'\n';
				ans=max(ans,sum);
			}
			ans2=min(ans2,ans);
//			cout<<"ans:"<<ans<<'\n';
			ans=0;
		}
		cout<<ans2<<'\n';
//		ans=0;
		ans2=1e9;
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
