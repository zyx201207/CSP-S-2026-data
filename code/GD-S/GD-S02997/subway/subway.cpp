#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char t=getchar();
	int res=0,bj=1;
	while(t<'0'||t>'9')
	{
		if(t=='-') bj=-1;
		t=getchar();
	}
	while(t>='0'&&t<='9')
	{
		res=res*10+(t-'0');
		t=getchar();
	}
	return res*bj;
}
void write(ll x)
{
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
ll Min(ll x,ll y)
{
	return (x<y)?x:y;
}
int c,n,m,d,q;
ll w[500005];
int k[500005];
ll a[505][25];
ll t[505][25];
ll dp[505][505]; 
bool vis[505][500005];
ll que[505],back;
short belong[500005][505];
short cnt[500005];
int mp[500005][505];
const ll INF=1e15;
ll x,y,res=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1; i<=m; i++)
	{
		w[i]=read();
	}
	for(int i=1; i<=n; i++)
	{
		k[i]=read();
		for(int j=1; j<=k[i]; j++)
		{
			//cin>>a[i][j]>>t[i][j];
			a[i][j]=read(),t[i][j]=read();
			belong[a[i][j]][++cnt[a[i][j]]]=i;
			vis[i][a[i][j]]=true;
			mp[a[i][j]][i]=t[i][j];
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			dp[i][j]=INF;
		}
		dp[i][i]=0;
	}
	/*
	for(int i=1; i<=m; i++)
	{
		cout<<cnt[i]<<"  ";
		for(int j=1; j<=cnt[i]; j++)
		{
			cout<<belong[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(vis[j][i]) que[++back]=j;
		}
		for(int j=1; j<=back; j++)
		{
			for(int u=1; u<=back; u++)
			{
				if(que[j]!=que[u]) dp[que[j]][que[u]]=Min(dp[que[j]][que[u]],mp[i][que[j]]+mp[i][que[u]]);//cout<<i<<" "<<que[j]<<" "<<que[u]<<" "<<mp[i][que[j]]<<" "<<mp[i][que[u]]<<"\n";
			}
		}
		back=0;
	}
	for(int u=1; u<=n; u++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(i!=j&&dp[i][u]!=INF&&dp[u][j]!=INF) dp[i][j]=Min(dp[i][j],dp[i][u]+dp[u][j]);
			}
		}
	}
	/*
	cout<<"\ndp:\n";
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	*/
	while(q--)
	{
		x=read(),y=read();
		res=INF;
		//cout<<cnt[x]<<" "<<cnt[y]<<"\n";
		for(int i=1; i<=cnt[x]; i++)
		{
			for(int j=1; j<=cnt[y]; j++)
			{
				if(dp[belong[x][i]][belong[y][j]]==INF) continue; 
				res=Min(res,dp[belong[x][i]][belong[y][j]]+mp[x][belong[x][i]]+mp[y][belong[y][j]]);
				//cout<<belong[x][i]<<" "<<belong[y][j]<<" "<<dp[belong[x][i]][belong[y][j]];
				//cout<<" "<<mp[x][belong[x][i]]<<" "<<mp[y][belong[y][j]]<<"\n";
			}
		}
		res+=w[x]+w[y];
		write(res);
		putchar('\n');
	}
	
	return 0;
}
/*
首先，乘坐地铁不需要时间
所以可以记录下起点和终点所在地铁站可以乘坐的线路，把地铁线路当成节点，把换乘所需最小时间作为边权 

0 3 7 20 2
8 3 6 1 7 2 9

3 
1 4 
2 5 
5 100
3 
2 6 
3 1 
7 2
4 
3 2 
5 100 
4 6 
6 7

1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
