#include<bits/stdc++.h>
using namespace std;
long long n,m,b[1000005],h[505][505],o[500005],g,k,l,p,q,d2,cnt,cnt1,head[700005],dis[100005],v[100005];
int d[500005][22],d1[500005][22];
struct W
{
	long long nxt,to,ll;
}w[100005];
void add(int x,int y,int z)
{
	w[++cnt].nxt=head[x];
	w[cnt].to=y;
	w[cnt].ll=z;
	head[x]=cnt;
}
struct node
{
	long long id,pos;
	bool operator<(const node &x )const
	{
		return x.pos<pos;
	}
};
long long read()
{
	long long ol=0,ui=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		ui=1;
		 c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ol=ol*10+c-'0';
		c=getchar();
		
	}
	return ol*ui;
}
priority_queue<node> q1;
void disja(int x)
{
	for(int i=1;i<=n+m;i++)
	dis[i]=1e18,v[i]=0;
	dis[x]=0;
	q1.push({x,0});
	while(!q1.empty())
	{
		int y=q1.top().id;
		q1.pop();
		if(v[y])
		continue;
		v[y]=1;
		for(int i=head[y];i;i=w[i].nxt)
		{
			int j=w[i].to;
			if(dis[j]>dis[y]+w[i].ll)
			{
				dis[j]=dis[y]+w[i].ll;
				q1.push({j,dis[j]});
			}
		}

		}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T;
	cin>>T>>n>>m>>d2>>q;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&b[i]);
	}
	if(m<=20005&&n<=200)
	{
			for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		for(int j=1;j<=k;j++)
		{
			long long x,y;
			scanf("%lld%lld",&x,&y);
			add(i,x+n,y);
			add(x+n,i,y);
		}
	}
	if(m<=1000)
	{long long rt[1005][1005];
		for(int i=1;i<=m;i++)
		{
			disja(i+n);
			
			for(int j=1;j<=m;j++)
			{
				rt[i][j]=dis[j+n];
			 } 
		}
		for(int i=1;i<=q;i++)
		{
			long long x,y;
			cin>>x>>y;
			cout<<rt[x][y]+b[x]+b[y]<<"\n";
		}
	}
	else
	{
		for(int i=1;i<=q;i++)
		{
			long long x,y;
			cin>>x>>y;
			disja(x+n);
			cout<<dis[y]<<"\n";
		}
	}
	}
	else
	{
	
		for(int i=1;i<=n;i++)
	{
		k=read();
		for(int j=1;j<=k;j++)
		{
			long long x,y;
		
			x=read();
			y=read();
			d[x][++o[x]]=i;
			d1[x][o[x]]=y;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			h[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=o[i];j++)
		{
			for(int k=j+1;k<=o[i];k++)
			{
				long long x=d[i][j];
				long long y=d[i][k];
				long long z=d1[i][j];
				long long z1=d1[i][k];
				h[x][y]=h[y][x]=min(h[y][x],z+z1);
				
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(h[i][k]&&h[j][k]&&i!=k&&j!=k&&i!=j)
				{
					h[i][j]=min(h[i][j],h[i][k]+h[j][k]);
					h[j][i]=h[i][j];
				}
			}
		}
	}

	for(int i=1;i<=q;i++)
	{
		long long x,y,ans=1e18;
		x=read();
		y=read();
		for(int j=1;j<=o[x];j++)
		{
			for(int k=1;k<=o[y];k++)
			{
				ans=min(ans,h[d[x][j]][d[y][k]]+d1[x][j]+d1[y][k]);
			}
		}
		ans+=b[x]+b[y];
		printf("%lld\n",ans);
	}
	}
	













































	return 0;
	
}
