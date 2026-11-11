#include<bits/stdc++.h>
#define inf 10000000000000000
using namespace std;
long long c,n,m,d,q,adafter[500010],ki,ai,ti,mp[510][510],ls,x,y,ans;
struct node{
	struct eg{
		int v,w;
	}e[20];
	int cnt=-1;
}t[500010];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>adafter[i];
	for(int i=1;i<=n;i++)
	{
		cin>>ki;
		for(int j=1;j<=ki;j++)
		{
			cin>>ai>>ti;
			++t[ai].cnt;
			t[ai].e[t[ai].cnt].v=i;
			t[ai].e[t[ai].cnt].w=ti;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)mp[i][j]=(i==j)?0:inf;
	for(int i=1;i<=m;i++)
		for(int j=0;j<=t[i].cnt;j++)
			for(int k=j+1;k<=t[i].cnt;k++)
				mp[t[i].e[j].v][t[i].e[k].v]=min(mp[t[i].e[j].v][t[i].e[k].v],(long long)t[i].e[j].w+t[i].e[k].w);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ls=min(mp[i][j],mp[j][i]),mp[i][j]=mp[j][i]=ls;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	while(q--)
	{
		cin>>x>>y;
		ans=inf;
		for(int i=0;i<=t[x].cnt;i++)
			for(int j=0;j<=t[y].cnt;j++)
				ans=min(ans,mp[t[x].e[i].v][t[y].e[j].v]+t[x].e[i].w+t[y].e[j].w);
		ans+=adafter[x]+adafter[y];
		cout<<ans<<'\n';
	}
	return 0;
}
