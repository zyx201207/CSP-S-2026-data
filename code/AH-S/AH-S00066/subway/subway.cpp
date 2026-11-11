#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
struct node 
{
	int w,l[25],top,t[25];
}v[505];
struct node1
{
	int k,a[505],t[505];
}line[100005];
long long ans;
bool us[505];
void dfs(int id,long long s,int la)
{ 
	if(s+v[y].t[la]>=ans) return;
	if(id==y)
	{
		ans=min(ans,s+v[y].t[la]);
		return; 
	}
	for(int i=1;i<=v[id].top;i++)
	{
		if(v[id].l[i]!=la) s+=v[id].t[la]+v[id].t[v[id].l[i]];
		for(int j=1;j<=line[v[id].l[i]].k;j++)
		{
			if(us[line[v[id].l[i]].a[j]]) continue;
			us[line[v[id].l[i]].a[j]]=true;
			dfs(line[v[id].l[i]].a[j],s,v[id].l[i]);
			us[line[v[id].l[i]].a[j]]=false;
		}
		if(v[id].l[i]!=la) s=s-v[id].t[la]-v[id].t[v[id].l[i]];
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>v[i].w;
	for(int i=1;i<=n;i++)
	{
		cin>>line[i].k;
		for(int j=1;j<=line[i].k;j++)
		{
			cin>>line[i].a[j]>>line[i].t[j];
			v[line[i].a[j]].l[++v[line[i].a[j]].top]=i;
			v[line[i].a[j]].t[i]=line[i].t[j];
		}
	}
	while(q--)
	{
		cin>>x>>y;
		ans=LLONG_MAX;
		for(int i=1;i<=n;i++) us[i]=false;
		dfs(x,v[x].w+v[y].w,0);
		cout<<ans<<'\n';
	}
	return 0;
}
