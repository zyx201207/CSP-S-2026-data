#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[1145141]; 
ll oi,ot;
ll kio;
ll ki[501][501];
ll u,v;
bool vis[6060];
vector<ll> du;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=501;i++)
	{
		for(int j=1;j<=501;j++)
		{
			ki[i][j]=0x7f7f7f7f7f7f7f7f;
		}
	}
	for(int i=1;i<=n;i++)
	{
	    cin>>kio;
	    int last,lastt;
	    cin>>last>>lastt;
	    vis[last]=1;
	    for(int j=2;j<=kio;j++)
	    { 
	    	cin>>oi>>ot;
	    	if(vis[oi])
	    	{
	    		du.push_back(oi);
			}
	    	vis[oi]=1;
	    	ki[last][oi]=ot+lastt;
	    	ki[oi][last]=ot+lastt;
	    	last=oi;
	    	lastt=ot;
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(ki[i][k]!=0x7f7f7f7f7f7f7f7f&&ki[k][j]!=0x7f7f7f7f7f7f7f7f) ki[i][j]=min(ki[i][k]+ki[k][j],ki[i][j]);
			}
		}
	}
	for(int k=0;k<du.size();k++)
	{
		int fq=du[k];
		for(int i=1;i<=fq;i++)
		{
			for(int j=fq;j<=n;j++)
			{
				if(ki[i][fq]!=0x7f7f7f7f7f7f7f7f&&ki[fq][j]!=0x7f7f7f7f7f7f7f7f)ki[i][j]=min(ki[i][fq]+w[fq]+ki[fq][j],ki[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>u>>v;
		cout<<ki[u][v]+w[v]+w[u]<<endl;
	}
	return 0;
}
