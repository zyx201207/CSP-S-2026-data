#include<bits/stdc++.h>
#define int long long
#define Furina using
#define de namespace
#define Fontaine std
Furina de Fontaine;
int c,t,n,m,u,v,dis1[1145141],dis2[1145141],dis3[1145141],dis4[1145141],dis5[1145141],d[1145141],du,dv,mdis,qcnt;
int tot=1,head[2333333],nxt[2333333],ed[2333333];
bool ond[1145141],vis[1145141];
vector<int> vc[1145141];
struct qry
{
	int x,y;
}q[1145141];
void init()
{
	mdis=0;
	for(int i=1;i<=n;i++)
	{
		head[i]=dis1[i]=dis2[i]=dis3[i]=dis4[i]=dis5[i]=0;
		ond[i]=vis[i]=false;
		vc[i].clear();
	}
	for(int i=1;i<=qcnt;i++)
	{
		q[i].x=q[i].y=0;
	}
	qcnt=0;
}
void ini()
{
	for(int i=1;i<=n;i++)
	{
		dis1[i]=dis2[i]=dis3[i]=dis4[i]=dis5[i]=0;
		vis[i]=false;
		vc[i].clear();
	}
	for(int i=1;i<=qcnt;i++)
	{
		q[i].x=q[i].y=0;
	}
	qcnt=0;
}
void chkmx(int& x,int y)
{
	if(y>x)
	{
		x=y;
	}
}
void add(int x,int y)
{
	tot++;
	ed[tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
void dfs1(int x,int y,int* dis,int& dpos,int& dmx)
{
	for(int i=head[x];i>0;i=nxt[i])
	{
		int to=ed[i];
		if(to!=y)
		{
			dis[to]=dis[x]+1;
			if(dis[to]>=dmx)
			{
				dmx=dis[to],dpos=to;
			}
			dfs1(to,x,dis,dpos,dmx);
		}
	}
}
void get(int x,int y,int z)
{
	d[z]=x;
	ond[z]=true;
	for(int i=head[x];i>0;i=nxt[i])
	{
		int to=ed[i];
		if(to!=y&&dis2[to]==dis2[x]-1)
		{
			get(to,x,z+1);
		}
	}
}
void dfs2(int x,int y,int z,int* dis,int pos)
{
	for(int i=head[x];i>0;i=nxt[i])
	{
		int to=ed[i];
		if(to!=y)
		{
			dis[to]=dis[x]+1;
			if(dis[to]==z+1)
			{
				if(!vis[to]&&!ond[to])
				{
					vis[to]=true;
					vc[pos].push_back(to);
				}
			}
//			else
//			{
				if(ond[x])
				{
					dfs2(to,x,z,dis,x);
				}
				else
				{
					dfs2(to,x,z,dis,pos);
				}
//			}
		}
	}
}
void dfs3(int x,int y,int& res,int& mx)
{
	for(int i=head[x];i>0;i=nxt[i])
	{
		int to=ed[i];
		if(to!=y&&dis3[to]==0&&dis4[to]==0)
		{
			dfs3(to,x,res,mx);
			chkmx(dis5[x],dis5[to]+1);
		}
	}
	if(dis5[x]>mx)
	{
		res++;
	}
}
int calc()
{
//	for(int i=1;i<=qcnt;i++)
//	{
//		cerr<<q[i].x<<" "<<q[i].y<<"\n";
//	}
//	cerr<<"\n";
	return 0;
}
bool check(int x)
{
	int pos1=d[x+1],pos2=d[mdis-x],res=0;
	dfs2(pos1,0,x,dis3,pos1);
	dfs2(pos2,0,x,dis4,pos2);
	for(int i=1;i<=n;i++)
	{
		//cerr<<dis1[i]<<" "<<dis2[i]<<" "<<dis3[i]<<" "<<dis4[i]<<"\n";
		chkmx(res,min(dis3[i],dis4[i]));
	}
	return res<=x;
	vc[d[x*2-1]].push_back(d[x*2]);
	vc[d[mdis-x*2+1]].push_back(d[mdis-x*2]);
	for(int i=1;i<=mdis;i++)
	{
		for(int j:vc[d[i]])
		{
			if(dis3[j]<=x||dis4[j]<=x)
			{
				continue;
			}
			//cerr<<"d:"<<d[i]<<" "<<j<<"\n";
			int y=0,z=x;
			dfs3(j,0,y,z);
			if(y==0)
			{
				qcnt++;
				q[qcnt]=(qry){i-(x-dis5[j]-1),i+(x-dis5[j]-1)};
			}
			else
			{
				res+=y;
			}
		}
	}
	return res+calc()<=m-2;
}
int bs()
{
	int l=1,r=(mdis+1)/2,mid=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		//cerr<<"mid:"<<mid<<"\n";
		if(check(mid))
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
		ini();
	}
	return l;
}
void solve()
{
	if(m==n)
	{
		printf("0\n");
		return;
	}
	dfs1(1,0,dis1,du,mdis);
	mdis=0;
	dfs1(du,0,dis2,dv,mdis);
	get(dv,0,1);
	mdis++;
//	cerr<<du<<"<=>"<<dv<<"\n";
//	for(int i=1;i<=mdis;i++)
//	{
//		cerr<<d[i]<<" ";
//	}
//	cerr<<"\n";
	printf("%lld\n",bs());
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n-1;i++)
		{
			scanf("%lld%lld",&u,&v);
			add(u,v),add(v,u);
		}
		solve();
		init();
	}
	return 0;
}
