#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int M=5e5+5;
int c,n,m,d,q;
int f[M];
vector<int>g1[M],v1[M];
int g2[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g2,0x3f,sizeof g2);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	g2[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",f+i);
	}
	for(int i=1;i<=n;i++)
	{
		int k,no,on;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%lld",&no);
			scanf("%lld",&on);
			g1[no].push_back(i);
			v1[no].push_back(on);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(g1[i].size()>1)
		for(int j1=0;j1<g1[i].size();j1++)
		for(int j2=j1+1;j2<g1[i].size();j2++)
		{
			int qq=v1[i][j1]+v1[i][j2];
			if(qq<g2[g1[i][j1]][g1[i][j2]])
			{
				g2[g1[i][j1]][g1[i][j2]]=qq;
				g2[g1[i][j2]][g1[i][j1]]=qq;
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int qq=g2[i][k]+g2[k][j];
				if(qq<g2[i][j])
				{
					g2[i][j]=qq;
					g2[j][i]=qq;
				}
			}
		}
	}
	int s,e,ans;
	while(q--)
	{
		scanf("%lld",&s);
		scanf("%lld",&e);
		ans=0x3f3f3f3f3f3f3f3f;
		for(int is=0;is<g1[s].size();is++)
		{
			for(int ie=0;ie<g1[e].size();ie++)
			{
				ans=fminl(ans,v1[s][is]+v1[e][ie]+g2[g1[s][is]][g1[e][ie]]);
			}
		}
		printf("%lld\n",ans+f[e]+f[s]);
	}
	return 0;
}
