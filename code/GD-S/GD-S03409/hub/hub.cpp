#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,c,T,fa[1000006][22],dep[1000006],lg[1000006],ans,k;
ll y_[15];
vector<int> ves[1000006];
void dfs(ll u,ll father)
{
	dep[u]=dep[father]+1;fa[u][0]=father;
	for(int i=1;i<=lg[dep[u]];i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i:ves[u])
	{
		if(i==father) continue;
		dfs(i,u);
	}
}
ll LCA(ll x,ll y)
{
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) 
	{
		x=fa[x][lg[dep[x]-dep[y]]-1];
	}
	if(x==y) return x;
	for(int i=lg[dep[x]]-1;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
ll fa_[15];
ll find(ll x)
{
	if(x==fa_[x]) return x;
	return fa_[x]=fa_[fa_[x]];
}
void dfs2(ll x,ll y[15])
{
	if(x==n+1)
	{
		ll z=0;
		for(int i=1;i<=n;i++) z+=y[i];
		if(z!=k) return ;
		for(int i=1;i<=n;i++) if(y[i]==1) fa_[i]=i;
		for(int i=1;i<=n;i++)
		{
			if(y[i]!=1) continue;
			for(int j:ves[i])
			{
				if(y[j]!=1) continue;
				ll num1=find(i),num2=find(j);
				if(num1!=num2) fa_[num1]=num2;
			}
		}
		ll num1=0,num2=0;
		for(int i=1;i<=n;i++) 
		{
			if(y_[i]==0) continue;
			if(num1==0) num1=fa_[i];
			else if(num2==0&&fa_[i]!=num1) num2=fa_[i];
			else if(num2!=fa_[i]&&num1!=fa_[i]) return ;
		}
		
		ll num=0;
		for(int i=1;i<=n;i++)
		{
			if(y[i]==0)
			{
				ll num0=1145141919810;
				for(int j=1;j<=n;j++) 
				{
					if(y[j]==0) continue;
					num0=min(num0,dep[i]+dep[j]-2*dep[LCA(i,j)]);
				}
				num=max(num,num0);
			}
		}
		ans=min(ans,num);
		return ;
	}
	y[x]=1;dfs2(x+1,y);
	y[x]=0;dfs2(x+1,y);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	for(int i=1;i<=1000000;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	cin>>c>>T;
	while(T--)
	{
		for(int i=1;i<=n;i++) dep[i]=0;
		for(int i=1;i<=n;i++) for(int j=0;j<=20;j++) fa[i][j]=0;
		for(int i=1;i<=n;i++) ves[i].clear();
		cin>>n>>k;ans=1145141919810;
		for(int i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
			ves[u].push_back(v);
			ves[v].push_back(u);
		}
		dfs(1,0);
		if(c<=3)
		{
			dfs2(0,y_);
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
