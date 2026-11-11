#include<iostream>
#include<vector>
#include<queue>
#define int long long
using namespace std;
inline int read(){char cc=getchar();int z=0,fh=1;while((cc<'0' || cc>'9') && cc!='-'){cc=getchar();}if(cc=='-'){fh=-1;cc=getchar();}while(cc>='0' && cc<='9'){z=z*10+cc-'0';cc=getchar();}return z*fh;}
inline void write(int x){if(x==0){putchar('0');return ;}if(x<0){x=-x;putchar('-');}int z[20],tt=0;while(x){z[++tt]=x%10;x/=10;}for(int i=tt;i;i--){putchar('0'+z[i]);}}
const int N=5e5+5;
int c,n,m,d,t;
int w[N];
int jl[505][505];
vector<pair<int,int>> dx[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q; 
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),t=read();
	for(int i=1;i<=m;i++)
	{
		w[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		int k=read();
		for(int j=1;j<=k;j++)
		{
			int a=read(),t=read();
			dx[a].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			jl[i][j]=1e18;
		}
		jl[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(auto a:dx[i])
		{
			for(auto b:dx[i])
			{
				int da=a.first,db=b.first;
				int wa=a.second,wb=b.second;
				jl[da][db]=min(jl[da][db],wa+wb);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				jl[i][j]=min(jl[i][j],jl[i][k]+jl[k][j]);
//				cout<<i<<' '<<j<<' '<<jl[i][j]<<"-=-\n";
			}
		}
	}
	while(t--)
	{
		int s=read(),t=read();
		int ans=1e18;
		for(auto a:dx[s])
		{
			for(auto b:dx[t])
			{
				ans=min(ans,a.second+b.second+jl[a.first][b.first]);
			}
		}
		write(ans+w[s]+w[t]);
		putchar('\n'); 
	}
	
	return 0;
}
/*
17:12:AC!
*/
