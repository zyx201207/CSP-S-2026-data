#include <bits/stdc++.h>
#define int long long
#define mp make_pair 
#define yi first
#define er second
using namespace std;
int a[500005];
set<pair<int,int> >g[1005];
struct node
{
	int x,st;
};
queue<node>q;
int fa[1005],k[500005];
int sta[500005][21],line[505];
int xxx[1005],yyy[1005];
int mapp[505][505];
int t1[500005],t2[500005];
int sign=0;
void bfs(int st,int en)
{
	while(!q.empty()) q.pop();
	memset(fa,127,sizeof(fa));
	fa[st]=0;
	q.push((node){st,a[st]+a[en]});
	while(!q.empty())
	{
		int nx=q.front().x,ny=q.front().st;
		q.pop();
		for(auto i=g[nx].begin();i!=g[nx].end();i++)
		{
			pair<int,int> ii=*i;
			if (fa[ii.yi]>ny+ii.er)
			{
				fa[ii.yi]=ny+ii.er;
				q.push((node){ii.yi,ny+ii.er});
			}
		}
	}
	cout<<fa[en]<<endl;
}
int c,n,m,d,qq;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++) cin>>a[i];
	if (c==20||c==21)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			for(int j=1;j<=k[i];j++)
			{
				int x,y;
				cin>>x>>y;
				if (i==1) t1[x]=y;
				else t2[x]=y;
			}
		}
		while(qq--)
		{
			int sttt,ennn;
			cin>>sttt>>ennn;
			if (t1[sttt]&&t1[ennn]) cout<<a[sttt]+a[ennn]<<endl;
			else if (t2[sttt]&&t2[ennn]) cout<<a[sttt]+a[ennn]<<endl;
			else
			{
				int mn=1e9;
				for(int i=1;i<=m;i++)
				{
					if (t1[i]&&t2[i]) mn=min(mn,t2[i]);
				}
				cout<<t1[sttt]+t2[sttt]+t1[ennn]+t2[ennn]+a[sttt]+a[ennn]+mn<<endl;
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>xxx[j]>>yyy[j];
			for(int kk=1;kk<j;kk++)
			{
				g[xxx[kk]].insert(mp(xxx[j],yyy[kk]+yyy[j]));
				g[xxx[j]].insert(mp(xxx[kk],yyy[kk]+yyy[j]));
			}
		}
	}
	while(qq--)
	{
		int st,en;
		cin>>st>>en;
		bfs(st,en);
	}
	return 0;
 } 
