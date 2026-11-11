#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,vis[1000001],d[1000001],minn=1e9,fa[1000001],de[1000001],maxx;
vector<int>e[1000001];
void ss(int x)
{
	vis[x]=1;
	for(int i=0;i<e[x].size();i++)
		if(vis[e[x][i]]==0)
			fa[e[x][i]]=x,de[e[x][i]]=de[x]+1,ss(e[x][i]);
	vis[x]=0;
}
int find(int i,int j)
{
	int cnt=0;
	if(de[i]>de[j])
		swap(i,j);
	while(de[j]>de[i])
		j=fa[j],cnt++;
	while(i!=j)
		i=fa[i],j=fa[j],cnt+=2;
	return cnt;
}
void dfs(int x,int ch,int fach,int kuai)
{
	if(kuai>2)
		return;
	if(ch==k)
	{
		maxx=-1;
		for(int i=1;i<=n;i++)
			if(vis[i]<2)
			{
				for(int j=1;j<=n;j++)
					if(vis[j]==2)
						d[i]=min(d[i],find(i,j));
				maxx=max(maxx,d[i]);
			}
		if(maxx>-1)
			minn=min(minn,maxx);
		return;
	}
	for(int i=0;i<e[x].size();i++)
		if(vis[e[x][i]]==0)
		{
			vis[e[x][i]]=2;
			if(fach==1)
				dfs(e[x][i],ch+1,1,kuai);
			else
				dfs(e[x][i],ch+1,1,kuai+1);
			vis[e[x][i]]=1;
			dfs(e[x][i],ch,0,kuai);
			vis[e[x][i]]=0;
		}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			e[i].clear(),vis[i]=0;
		for(int i=1;i<n;i++)
			cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
		fa[1]=1,de[1]=1;
		ss(1);
		dfs(1,0,0,0);
		dfs(1,1,1,1);
		cout<<minn<<"\n";
	}
	return 0;
}
