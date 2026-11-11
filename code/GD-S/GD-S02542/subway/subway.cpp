#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5;
int c,n,m,d,qq,w[M],k,a[M],b[M],x,y,tt[N][N],bo[N];
struct stu
{
	int no,t;
};
vector<stu>g[M];
int in()
{
	int w=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		w=w*10+c-'0';
		c=getchar();
	}
	return w*f;
}
struct stu2
{
	int x,no,t;
};
queue<stu>q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++) w[i]=in();//µØÌú¿Úµ½Õ¾Ìü
	for(int i=1;i<=n;i++)
	{
		k=in();
		for(int j=1;j<=k;j++)
		{
			a[j]=in();b[j]=in();
		}
		g[a[1]].push_back({a[2],b[1]});
		g[a[2]].push_back({a[1],b[2]});
	} 
	for(int i=1;i<=qq;i++) 
	{
		memset(bo,0x3f,sizeof(bo));
		int ans=1000000000;
		x=in();y=in();
//		for(int i=0;i<g[x].size();i++)
//			q.push({x,g[x][i].no,w[x]+g[x][i].t});
		q.push({x,0});
		bo[x]=0;
		while(q.size())
		{
			stu r=q.front();
			if(r.no==y||bo[r.no]!=r.t) 
			{
				q.pop();
				continue;
			}
			for(int j=0;j<g[r.no].size();j++)
			{
				if(bo[g[r.no][j].no]<=g[r.no][j].t+w[r.no]+r.t) continue;
//				cout<<g[r.no][j].no<<endl;
				q.push({g[r.no][j].no,g[r.no][j].t+w[r.no]+r.t});
				bo[g[r.no][j].no]=min(bo[g[r.no][j].no],g[r.no][j].t+w[r.no]+r.t);
				if(g[r.no][j].no==y) 
				{
					ans=min(ans,g[r.no][j].t+r.t);
					break;
				}
			}
			q.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
} 
