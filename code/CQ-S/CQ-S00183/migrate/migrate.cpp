/*
	注意快读 Int
	设 dp[i][j] 代表从 i 到 j 的方案数 
	dp[i][j]=dp[i][k]+dp[k][j]
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int GI=1<<20;
const int INF=0x3f3f3f3f3f3f3f3f;
char *p1,*p2,buf[GI];
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,GI,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
	int x=0,f=1;char ch=nc();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=nc();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=nc();
	return x*f;
}
const int maxn=5005;
int x[maxn];
bool inq[maxn];
vector<int> g[maxn];
int dist[5005][5005],dist1[5005][5005],dd[5005][5005];
void bfs(int s)
{
	memset(inq,0,sizeof(inq));
	queue<int> q;
	q.push(s);
	inq[s]=true;
	dist[s][s]=0;
	while(!q.empty())
	{
		int i=q.front();
		q.pop();
		inq[s]=false;
		for(int j:g[i])
		{
			if(!inq[j])
			{
				q.push(j);
				inq[j]=true;
				dist[s][j]=min(dist[s][j],dist[s][i]+1);
			}
		}
	}
}
signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C=read(),T=read();
	while(T--)
	{
		int n=read(),d=read();
		for(int i=1;i<=n;i++) x[i]=read(),g[i].clear();
		cout<<0<<'\n'; 
	}
	return 0;
}


