#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5e3+5,N=5e2+5;
typedef long long ll;
int c,n,m,d,qq,w[M*25],v[M*25],kk[N],nt[M*25],tot,head[M*25],ww[M];
vector<int>a[N],in[M],t[N],w2[M];
void init()
{
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)cin>>ww[i];
	for(int i=1;i<=n;i++)
	{
		cin>>kk[i];
		a[i].push_back(0);t[i].push_back(0);
		for(int j=1;j<=kk[i];j++)
		{
			int ta,tt;
			cin>>ta>>tt;
			a[i].push_back(ta);
			t[i].push_back(tt);
			in[a[i][j]].push_back(i);
			w2[a[i][j]].push_back(t[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=kk[i];j++)for(int k=0;k<in[a[i][j]].size();k++)
			if(in[a[i][j]][k]!=i)
			{
				v[++tot]=in[a[i][j]][k];
				w[tot]=t[i][j]+w2[a[i][j]][k];
				nt[tot]=head[i];
				head[i]=tot;
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=kk[i];j++)
		{
			v[++tot]=n+a[i][j];
			w[tot]=t[i][j];
			nt[tot]=head[i];
			head[i]=tot;
		}
}
	int inq[M],dis[M];
priority_queue<pair<int,int> >q;
void solve()
{
	int ans[n+5][m+5];
	for(int i=1;i<=n;i++)
	{
		memset(inq,0,sizeof(inq));
		memset(dis,0x3f,sizeof(dis));
		q.push({0,i});dis[i]=0;
		while(!q.empty())
		{
			int nod=q.top().second;q.pop();
			for(int j=head[nod];j;j=nt[j])
			{
				if(dis[v[j]]>dis[nod]+w[j])
				{
					dis[v[j]]=dis[nod]+w[j];
					if(!inq[v[j]])
					{
						inq[v[j]]=1;
						q.push({-dis[v[j]],v[j]});
					}
				}
			}
		}
		for(int j=n+1;j<=n+m;j++)ans[i][j-n]=dis[j];
	}
	while(qq--)
	{
		int u,v,aan=1e9;
		cin>>u>>v;
		for(int i=0;i<in[u].size();i++)
		{
			aan=min(ans[in[u][i]][v]+w2[u][i],aan);
		}
		cout<<aan+ww[u]+ww[v]<<'\n';
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	init();
	solve();
	return 0;
}
