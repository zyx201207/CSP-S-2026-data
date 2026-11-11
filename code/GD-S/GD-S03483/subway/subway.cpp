#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x7f7f7f7f;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
		x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
inline void write(int x)
{
	if(x==0){
		putchar('0');
		return ;
	}
	if(x<0){
		putchar('-');
		x=-x;
	}
	int tot=0;
	char c[64];
	while(x>0){
		c[tot++]=x%10+'0';
		x/=10;
	}
	while(tot>0)
		putchar(c[--tot]);
}
int c,n,m,d,q,w[500005],ans[500005],a[500005],t[500005],mmap[10001][10001];
bool f[500005];
vector<int>dis[500005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >qu;
inline void dij(int x,int fg)
{
	ans[x]=0;
	qu.push(pair<int,int>(0,x));
	while(!qu.empty()){
		x=qu.top().second;
		qu.pop();
		if(f[x])continue;
		f[x]=true;
		for(int i=0,y;i<dis[x].size();i++)
		{
			y=dis[x][i];
			if(ans[y]>ans[x]+mmap[x][y]+mmap[y][x])
				ans[y]=ans[x]+mmap[x][y]+mmap[y][x];	
			qu.push(pair<int,int>(ans[y],y));
		}
	}
	
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	 for(int i=1;i<=m;i++)
	 	w[i]=read();
	for(int i=1,k;i<=n;i++)
	{
		k=read();
		for(int j=1;j<=k;j++)
		{
			a[j]=read(),t[j]=read();
			for(int z=1;z<j;z++){
				dis[a[z]].push_back(a[j]);
				dis[a[j]].push_back(a[z]);
				mmap[a[z]][a[j]]=t[z];
				mmap[a[j]][a[z]]=t[j];
			}
		}
	}
	while(q--)
	{
		int x=read(),y=read();
		memset(ans,INF,sizeof(ans));
		memset(f,false,sizeof(f));
		dij(x,y);
		ans[y]+=w[x]+w[y];
		write(ans[y]);
		putchar('\n');
	}
	return 0;
}
