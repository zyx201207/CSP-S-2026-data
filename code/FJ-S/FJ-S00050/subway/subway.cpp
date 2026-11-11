#include<bits/stdc++.h>
using namespace std;
long long dv[505][505];
struct node{
	long long v,w;
};
vector<node>e[500005],e2[1000];
long long ti[500005],k;
long long c,n,m,d,q;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	cin>>ti[i];
	for(long long i=1;i<=n;i++)
	{
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			long long a,x;
			cin>>a>>x;
			node g1;
			g1.v=i+m;g1.w=x;
			e[a].push_back(g1);
		}
	}
	memset(dv,0x3f,sizeof(dv));
	for(int i=1;i<=n;i++)
	dv[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size() ;j++)
		{
			for(int k=j;k<e[i].size() ;k++)
			{
				dv[e[i][j].v-m][e[i][k].v-m]=min(dv[e[i][j].v-m][e[i][k].v-m],e[i][j].w+e[i][k].w);
				dv[e[i][k].v-m][e[i][j].v-m]=dv[e[i][j].v-m][e[i][k].v-m];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++){
				if(dv[j][k]>dv[j][i]+dv[i][k]){
					dv[j][k]=dv[j][i]+dv[i][k];
					dv[k][j]=dv[j][k];
				}
				
			}
		}
	}
	while(q--)
	{
		long long a,b;
		cin>>a>>b;
		long long ans=1000000000000000;
		for(long long i=0;i<e[a].size();i++)
		{
			long long tt=e[a][i].v;
			for(long long j=0;j<e[b].size();j++)
			{
				long long tt2=e[b][j].v;
				ans=min(dv[tt-m][tt2-m]+e[a][i].w+e[b][j].w,ans);
			}
		}
		cout<<ans+ti[a]+ti[b]<<'\n';
	}
	return 0;
}
