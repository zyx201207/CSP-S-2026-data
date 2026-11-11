#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
#define pb emplace_back

namespace kanade
{
	int read()
	{
		int ans=0,fs=1;
		char ch=getchar();
		while(ch<'0'||ch>'9')
		{
			if(ch=='-')fs=-1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9')
		{
			ans=ans*10+ch-'0';
			ch=getchar();
		}
		return ans*fs;
	}

	ll dis[510][510];
	int A[500010][22],id[500010][22],P[500010],W[500010];

	int main()
	{
		int c=read(),n=read(),m=read(),d=read(),q=read();
		for(int i=1;i<=m;i++)
		{
			W[i]=read();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)dis[i][j]=(i==j)?0:1e18;
		}
		for(int i=1;i<=n;i++)
		{
			int k=read();
			for(int j=1;j<=k;j++)
			{
				int a=read(),t=read();
				P[a]++,id[a][P[a]]=i,A[a][P[a]]=t;
			} 
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=P[i];j++)
			{
				for(int k=j+1;k<=P[i];k++)
				{
					int a=id[i][j],b=id[i][k];
					ll t=A[i][j]+A[i][k];
					dis[a][b]=dis[b][a]=min(dis[a][b],t);
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		while(q--)
		{
			int x=read(),y=read();
			ll ans=1e18;
			for(int i=1;i<=P[x];i++)
			{
				for(int j=1;j<=P[y];j++)
				{
					
					ans=min(ans,dis[id[x][i]][id[y][j]]+W[x]+W[y]+A[x][i]+A[y][j]);
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	kanade::main();
	return 0;
}

//就数你就数你就数你
//92612k=92m

