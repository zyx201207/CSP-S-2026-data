#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,jg,jjg,qd,zd,ans;
int mapp[6000][6000];
struct nood
{
	int t[500],kt;
}k[600];
void dfs(int x)
{
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>k[i].kt;
	}
	for(int i=1;i<=n;i++)
	{
		int p;
		cin>>p;
		for(int j=1;j<=p;j++)
		{
			jjg=jg;
			cin>>jg>>k[jg].t[i];
			mapp[jjg][jg]++;
			mapp[jg][jjg]++;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>qd>>zd;
		dfs(qd);
		cout<<ans;
	}
	return 0;
}
