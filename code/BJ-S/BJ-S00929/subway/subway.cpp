#include <bits/stdc++.h>
#define AFO long long
using namespace std;
const int N=2e6+5;
struct node
{
	int y,z;
};
struct nq
{
	int x;
	AFO dis;
};
bool operator < (nq x,nq y)
{
	return x.dis>y.dis;
}
priority_queue<nq>q;
vector<node>a[N];
int w[N],z[N];
bool v[N];
AFO d[N];
int c,n,m,dd,qr,tot;
void dij(int s,int t)
{
	for(int i=1;i<=tot;i++)
		d[i]=1e18,v[i]=0;
	q.push({s,0});
	d[s]=0;
	while(!q.empty())
	{
		int x=q.top().x;
		if(x==t)
		{
			//for(int i=1;i<=tot;i++)
			//	cout<<d[i]<<" "<<z[i]<<"\n";
			cout<<d[x]+w[s]+w[t]<<"\n";
			return ;
		}
		q.pop();
		if(v[x])
			continue;
		v[x]=1;
		for(int i=0;i<a[x].size();i++)
		{
			int y=a[x][i].y,z=a[x][i].z;
			if(d[y]>d[x]+z)
			{
				d[y]=d[x]+z;
				q.push({y,d[y]});
			}
		}
	}
}
void kklldk()
{/*
	通知 - 第二题样例说明
	第二题（subway）中的样例解释请忽略公式中的变量部分，以文字叙述部分与公式中的数值部分为准。
1	第一题：能量水晶	2026-10-31 15:14:06	512B	
2	第二题：地铁	未提交		
3	第三题：迁徙	未提交		
4	第四题：研发基地	未提交		
四个部分分，一个没条出来，100+0+0+0
大概是AFO了吧，AFO(2024.7.15-2026.10.31)
我咋这么菜/ll
good bye OI.
hello whk.
luogu:wangzexun
in 北京信息科技学院
*/
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>dd>>qr;
	tot=m;
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int k,lst=0;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			tot++;
			if(lst)
			{
				a[tot].push_back({lst,0});
				a[lst].push_back({tot,0});
			}
			a[tot].push_back({x,y});
			a[x].push_back({tot,y});
			lst=tot,z[tot]=x;
		}
	}
	while(qr--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		dij(x,y);
	}
/*
0 3 12 10 1000
0 0 0 0 0 0 0 0 0 0 0 0
5 3 1 2 6 8 4 11 5 12 7
4 1 2 2 6 4 3 5 10
5 6 4 5 9 9 4 11 12 10 11
12 1
*/
/*#include <bits/stdc++.h>
using namespace std;
const int N=105;
vector<int>a[N],b[N];
int w[N];
int c,n,m,d,q,ans,cnt;
bool f;
void dfs(int x,int y,int sum,int t)
{
	if(x==y&&t==0)
	{
		cnt++;
		f=1;
		ans=min(ans,sum+w[y]);
		return ;
	}
	if(!t)
	{
		for(int i=1;i<=n;i++)
			for(int j=0;j<a[i].size();j++)
				if(a[i][j]==x&&cnt<=0)
					dfs(x,y,sum+b[i][j],i);
	}
	else
	{
		for(int i=0;i<a[t].size();i++)
		{
			if(a[t][i]==x&&cnt<=100)
			{
				if(i)
					dfs(a[t][i-1],y,sum,t);
				if(i!=a[t].size()-1)
					dfs(a[t][i+1],y,sum,t);
				dfs(x,y,sum+b[t][i],0);
			}
		}
	}
}
int main()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x;
			cin>>x;
			a[i].push_back(x);
			a[x].push_back(i);
			cin>>x;
			b[i].push_back(x);
			b[x].push_back(i);
		}
	}
	while(q--)
	{
		ans=2e9;
		int x,y;
		cin>>x>>y;
		dfs(x,y,w[x],0);
		cout<<ans<<"\n";
	}
	return 0;
}
*/
	return 0;
}
