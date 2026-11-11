#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct line
{
	long long a,t;
}inp;
vector<line> jg[500050];
long long c,n,m,d,q,w[500050],f[505][505],kc[505],ai,ti,st,en,ans,jj,kk;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++) scanf("%lld",&w[i]);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld",&kc[i]);
		for(int j = 1;j <= kc[i];j++)
		{
			scanf("%lld%lld",&ai,&ti);
			inp.a = i;
			inp.t = ti;
			jg[ai].push_back(inp);
		}
	}
	memset(f,0x7f,sizeof(f));
	for(int i = 1;i <= m;i++)
	{
		for(int j = 0;j < jg[i].size();j++)
		{
			for(int k = j+1;k < jg[i].size();k++)
			{
				f[jg[i][k].a][jg[i][j].a] = f[jg[i][j].a][jg[i][k].a] = min(f[jg[i][j].a][jg[i][k].a],jg[i][j].t + jg[i][k].t);
				//cout << f[jg[i][j].a][jg[i][k].a] << " ";
			}
		}
	}
	for(int i = 1;i <= n;i++) f[i][i] = 0;
	//cout << endl;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			for(int k = 1;k <= n;k++)
			{
				if(f[j][i] <= 8000000000000 && f[k][i] <= 8000000000000) f[k][j] = f[j][k] = min(f[j][k],f[j][i]+f[k][i]);
			}
		}
	}
//	for(int i = 1;i <= n;i++)
//	{
//		for(int j = 1;j <= n;j++)
//		{
//			cout << f[i][j] << " ";
//		}
//		cout << endl;
//	}
	for(int i = 1;i <= q;i++)
	{
		scanf("%lld%lld",&st,&en);
		ans = 2e17;
		for(int j = 0;j < jg[st].size();j++)
		{
			for(int k = 0;k < jg[en].size();k++)
			{
				if(f[jg[st][j].a][jg[en][k].a] + jg[st][j].t + jg[en][k].t < ans)
				{
					jj = j;
					kk = k;
					ans = min(ans,f[jg[st][j].a][jg[en][k].a] + jg[st][j].t + jg[en][k].t);
				}
			}
		}
		ans += w[st] + w[en];
		printf("%lld\n",ans);
	}
	return 0;	
}
