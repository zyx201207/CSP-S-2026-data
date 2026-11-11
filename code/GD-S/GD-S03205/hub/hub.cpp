#include<bits/stdc++.h>
using namespace std;
const int N=1000009;
int deep[N][2],bz[N],fa[N],far,c,T,n,k,u[N],v[N];
vector<int> g[N];
void work(int x,int fa,int remu,int remv,int o)
{
	deep[x][o]=deep[fa][o]+1;
	if(deep[x][o]>deep[far][o]) far=x;
	for(int v:g[x])
	{
		if(v==fa) continue;
		if(x==remu&&v==remv) continue;
		if(v==remu&&x==remv) continue;
		work(v,x,remu,remv,o);
	}
}
int dg(int x,int faa)
{
	int minn=1147483647;
	if(bz[x]!=0) return 0;
	for(int v:g[x])
	{
		if(v==faa) continue;
		minn=min(minn,dg(v,x));
	}
	return minn+1;
}
int getfa(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&u[i],&v[i]);
			g[u[i]].push_back(v[i]);
			g[v[i]].push_back(u[i]);
		}
		if(c<=3)
		{
			int ans=1147483647;
			for(int S=0;S<(1<<n);S++)
			{
				int sum=0;
				for(int i=0;i<n;i++)
				{
					if(S&(1<<i)) bz[i+1]=1,sum++;
					else bz[i+1]=0;
				}
				if(sum!=k) continue;
				for(int i=1;i<=n;i++) fa[i]=i;
				for(int i=1;i<n;i++)
				{
					if(bz[u[i]]&&bz[v[i]])
						if(getfa(u[i])!=getfa(v[i]))
							fa[getfa(u[i])]=getfa(v[i]);
				}
				sum=0;
				for(int i=1;i<=n;i++)
					if(bz[i]==1&&bz[getfa(i)]!=2)
						bz[getfa(i)]=2,sum++;
				if(sum>2) continue;
				int tj=0;
				for(int i=1;i<=n;i++)
					tj=max(tj,dg(i,i));
				ans=min(ans,tj);
			}
			printf("%d\n",ans);
		}
		else
		{
			deep[0][0]=deep[0][1]=-1;
			int ans=1147483647;
			for(int i=1;i<n;i++)
			{
				far=0; deep[v[i]][0]=0;
				work(u[i],v[i],u[i],v[i],0);
				int fir=far;
				far=0; deep[fir][0]=0;
				work(fir,fir,u[i],v[i],0);
				fir=far;
				
				far=0; deep[v[i]][1]=0;
				work(v[i],u[i],u[i],v[i],1);
				int sec=far;
				far=0; deep[sec][1]=0;
				work(sec,sec,u[i],v[i],1);
				sec=far;
				
				ans=min(ans,max((deep[fir][0]+1)/2,(deep[fir][1]+1)/2));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
