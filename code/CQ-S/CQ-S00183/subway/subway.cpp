/*
	将每条线路看作一个集合
	两个集合中有边当且仅当其中有重复元素
	边权就是其中换乘的最小值
	最后跑一遍 Floyd 即可 
	O(nm*20+nq*20+n^3) 期望得分 92 
	
	想上迷惑行为大赏 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int GI=1<<20;
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
const int maxm=1e6+7;
int w[maxm],dist[505][505];
int C,n,m,d,q; 
unordered_map<int,int> mp[502];
vector<int> v[maxm];
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		int k=read();
		for(int j=1;j<=k;j++) 
		{
			int u=read(),t=read();
			mp[i][u]=t;
			for(int x:v[u])
			{
				int xx=mp[x][u];
				dist[i][x]=min(dist[i][x],xx+t),dist[x][i]=min(dist[x][i],xx+t);
			}
			v[u].push_back(i);
		}
	}
	for(int i=1;i<=n;i++) dist[i][i]=0;
	for(int x=1;x<=n;x++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][x]+dist[x][j]);
	while(q--)
	{
		int x=read(),y=read();
		int ans=LLONG_MAX;
		for(int p:v[x])
			for(int pp:v[y]) ans=min(ans,dist[p][pp]+mp[p][x]+mp[pp][y]);
		printf("%lld\n",ans+w[x]+w[y]);
	}
}/*
void solve2()
{
	int T;
	for(int i=1;i<=n;i++)
	{
		int k=read();
		for(int j=1;j<=k;j++) 
		{
			int u=read(),t=read();
			T=t;
			mp[i][u]=t;
			for(int x=1;x<i;x++)
				if(mp[x][u])
				{
					int xx=mp[x][u];
					dist[i][x]=t*2,dist[x][i]=t*2;
				}
		}
	}
	for(int i=1;i<=n;i++) dist[i][i]=0;
	for(int x=1;x<=n;x++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][x]+dist[x][j]);
	while(q--)
	{
		int x=read(),y=read();
		int ans=T*4;
		printf("%lld\n",ans+w[x]+w[y]);
	}
}*/
signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read(); 
	memset(dist,0x3f,sizeof(dist));
	solve1();
//	if(1<=C&&C<=8) solve1();
//	else if(C==20||C==21) solve1();
//	else if(12<=C&&C<=19) solve2();
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			cout<<i<<' '<<j<<' '<<dist[i][j]<<'\n';

	return 0;
}


