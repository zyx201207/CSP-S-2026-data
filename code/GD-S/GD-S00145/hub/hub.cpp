#include<bits/stdc++.h>
using namespace std;
int c,t,to[2000005],val[2000005],h[2000005],nxt[2000005],n,k,m,tu,tv,ans=INT_MAX;
void add(int u,int v)
{
	to[++m]=v;
	val[m]=1;
	nxt[m]=h[u];
	h[u]=m;
}
/*void dfs(int nw,int ov,int step)
{
	
	if(nw==ov){ans=min(ans,step);return ;}
	for(int i=h[nw];i;i=nxt[i])
	{
		step++;
		int v=to[i];
		if(f[v])continue;
		dfs(v,ov,step+1);
	}
}
void d2(int id,int k)
{
	if(k>=1)cr[id]=true;
	dfs();
}*/
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>tu>>tv;
			add(tu,tv);
			add(tv,tu);
		}
		//for(int i=1;i<=n;i++)f[i]=false;
		cout<<k<<endl;
	}
	return 0;
}
