#include<bits/stdc++.h>
#define ll long long//好了这个也是一点都不对。 
using namespace std;

const int N=2e6+5;
const int inf=1e18+5; 
//d<=2e18

int c,t,n,d;
ll x[N];

struct edge
{
	int to,nxt;
}ed[N*4];


int hed[N*4],cnt;
void add(int u,int v)
{
	ed[++cnt].to=v;
	ed[cnt].nxt=hed[u];
	hed[u]=cnt;
}

ll Cnt,num,min_cnt=inf;//当前飞行次数 最短路径数 最短路径飞行次数 
void Dfs(int x,int goal)
{
	Cnt++;
	if(Cnt>min_cnt)
		return;
	if(x==goal)
	{
		if(Cnt==min_cnt)
			num++;
		else
		{
			min_cnt=Cnt;
			num=0;
		}
		return;
	}
	for(int i=hed[x]; ;i=ed[i].nxt)
	{
		if(ed[i].to>goal)
			continue;
		Dfs(ed[i].to,goal);
	}
	Cnt--;
}

int ans=0;
void work(int u,int v)
{
	num=Cnt=0;
	min_cnt=inf;
	Dfs(u,v);
	if(num==2)
		ans++;
}

int main( )
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--)
	{
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			for(int j=1;j<i;j++)
			{
				int cz=x[i]-x[j];
				if(cz<=d)
					add(j,i);
				else
					break;
			}
		}
	
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				work(i,j);//查找i j之间的路径 
				
		cout<<ans<<endl;
	}
	
	return 0;
}
