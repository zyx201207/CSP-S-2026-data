#include <bits/stdc++.h>
using namespace std;
const int MAXM=5e5+5,MAXN=505;
int n,d,c,k,q,xr,yr;
long long m,w[MAXM],w2[MAXN][MAXN];
struct K
{
	long long id,t;
};
vector<K> e[MAXN];
vector<int> e2[MAXM];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			K x;
			cin>>x.id>>x.t;
			e[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<e[i].size();j++)
		{
			e2[e[i][j].id].push_back(i);
		}
	}
	memset(w2,0x3f,sizeof(w2));
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<e[i].size();j++)
		{
			for(int k=0;k<e2[e[i][j].id].size();k++)
			{
				long long tt=e2[e[i][j].id][k];
				w2[i][tt]=min(w2[i][tt],e[i][k].t+e[tt][j].t);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				w2[i][j]=min(w2[i][j],w2[i][k]+w2[k][j]);
		}
	}
	while(q--)
	{
		cin>>xr>>yr;
		long long ans=w[xr]+w[yr],t1=1e18;
		for(int i=0;i<e2[xr].size();i++)
		{
			for(int j=0;j<e2[yr].size();j++)
			{
				int tt1=e2[xr][i],tt2=e2[yr][j];
				t1=min(t1,w2[tt1][tt2]);
			}
		}
		cout<<ans+t1<<"\n";
	}
	return 0;
}
