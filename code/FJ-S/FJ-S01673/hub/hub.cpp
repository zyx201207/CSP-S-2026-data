#include<bits/stdc++.h>
using namespace std;
int u[106],v[106],f[106],pd[106],zhan[106],e[106][106];
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void mer(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y) f[x]=y;
}
void suan()
{
	memset(e,63,sizeof(e));
	int n,k,ans=1e9;
	cin>>n>>k;
	for(int i=1;i<=n;i++) e[i][i]=0;
	for(int i=1;i<n;i++)
	{
		cin>>u[i]>>v[i];
		e[u[i]][v[i]]=e[v[i]][u[i]]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
	for(int ii=0;ii<(1<<n);ii++)
	{
		for(int j=1;j<=n;j++) pd[j]=((ii>>j-1)&1);
		int js=0;
		for(int i=1;i<=n;i++) js+=pd[i];
		if(js!=k) continue; 
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<n;i++) if(pd[u[i]]&&pd[v[i]]) mer(u[i],v[i]);
		int cnt=0;
		for(int i=1;i<=n;i++) if(pd[i]) zhan[++cnt]=find(i);
		cnt=unique(zhan+1,zhan+cnt+1)-1-zhan;
		if(cnt!=2) continue;
//		for(int i=1;i<=n;i++)
//		{
//			if(pd[i]) cout<<i<<' ';
//		}
//		cout<<'\n';
		int jl=0;
		for(int i=1;i<=n;i++)
		{
			if(pd[i]) continue;
			int jl2=1e9;
			for(int j=1;j<=n;j++) if(pd[j]) jl2=min(jl2,e[i][j]);
			jl=max(jl,jl2);
		}
		ans=min(ans,jl);
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) suan();
	return 0;
}

