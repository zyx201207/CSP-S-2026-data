#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k,o,p;long long ans=1e18;
vector<int>xian[505];int ti[505][500005];
vector<int>huan[500005];bool f[500005];
void dfs(int xi,int ov,long long sum)
{
	for(int i=0;i<xian[xi].size();i++)
	{
		int v=xian[xi][i];
		if(v==ov)
		{
			ans=min(ans,sum+ti[xi][v]);
			return ;
		}
		if(huan[v].size()==0)continue;
		if(f[v])continue;
		for(int i=0;i<huan[v].size();i++)
		{
			int nx=huan[v][i];
			if(nx!=xi)
			{
				f[v]=true;
				dfs(nx,ov,sum+ti[xi][v]+ti[nx][v]);
				f[v]=false;
			}
		}
		
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;int idt,tit;
		for(int j=1;j<=k;j++)
		{
			cin>>idt>>tit;
			huan[idt].push_back(i);
			xian[i].push_back(idt);
			ti[i][idt]=tit;
		}
	}
	while(q--)
	{
		for(int i=1;i<=m;i++)f[i]=false;
		cin>>o>>p;
		ans=1e18;
		for(int i=0;i<huan[o].size();i++)
		{
			dfs(huan[o][i],p,ti[o][huan[o][i]]);
		}
		cout<<ans+w[o]+w[p]<<endl;
	}
	return 0;
}
