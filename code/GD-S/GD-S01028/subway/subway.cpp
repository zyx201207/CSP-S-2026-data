#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=505;
int c,n,m,d,q,w[N],k[N],o1,o2;
long long ans;
bool b[N],p[N];
struct node
{
	int a,t;
};
vector<node> v[M];
vector<node> r[N];
void dfs(int x,int y,long long cnt,bool z)
{
	if(x==y&&z)
	{
		ans=min(ans,cnt);
		return;
	}
	if((z&&b[x])||(!z&&p[x]))return;
	if(z)
	{
		b[x]=1;
		for(int i=0;i<r[x].size();i++)
		{
			dfs(r[x][i].a,y,cnt+r[x][i].t,0);
		}
	}
	else
	{
		p[x]=1;
		for(int i=0;i<v[x].size();i++)
		{
			dfs(v[x][i].a,y,cnt+v[x][i].t,1);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>o1>>o2;
			v[i].push_back({o1,o2});
			r[o1].push_back({i,o2});
		}
	}
	int x,y;
	for(int i=1;i<=q;i++)
	{
		ans=10000000000013;
		cin>>x>>y;
		for(int j=1;j<=n;j++)p[j]=0;
		for(int j=1;j<=m;j++)b[j]=0;
		dfs(x,y,0,1);
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
