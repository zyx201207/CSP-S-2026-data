#include<bits/stdc++.h>
using namespace std;
int ccc,n,m,d,q;
int w[500005];
int k[500005];
int c,b[500005][4],a[500005];
int cc,bb[500005][4],aa[500005];
int bj[500005];
int mn;
void add(int u,int v,int z)
{
	c++;
	b[c][0]=u;
	b[c][1]=v;
	b[c][2]=z;
	b[c][3]=a[u];
	a[u]=c;
}
void aadd(int u,int v,int z)
{
	cc++;
	bb[cc][0]=u;
	bb[cc][1]=v;
	bb[cc][2]=z;
	bb[cc][3]=aa[u];
	aa[u]=cc;
}
void dfs(int qs,int zs,int ans)
{
	if(qs==zs)
	{
		mn=min(mn,ans);
		return;
	}
	for(int i=aa[qs];i!=0;i=bb[i][3])
	{
		int v=bb[i][1];
		int d=bb[i][2];
		for(int j=a[v];j!=0;j=b[j][3])
		{
			if(bj[b[j][1]]==0)
			{
				bj[b[j][1]]=1;
				dfs(b[j][1],zs,ans+d+b[j][2]); 
				bj[b[j][1]]=0;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ccc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int aa,tt;
			cin>>aa>>tt;
			add(i,aa,tt);
			aadd(aa,i,tt);
		}
	}
	while(q--)
	{
		int xr,yr;
		cin>>xr>>yr;
		mn=INT_MAX;
		dfs(xr,yr,w[xr]+w[yr]);
		cout<<mn<<endl;
	}
	return 0;
}
