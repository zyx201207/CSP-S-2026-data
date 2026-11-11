#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[2000005];
long long kn[505],a[505][50005],t[505][50005],x,y,kkk=INT_MAX;
bool f[2000005],p=0;
void dfs(long long qs,long long zd,long long s)
{
	if(p==1)
	{
		return ;
	}
	if(qs==zd)
	{
		p=1;
		return ;
	}
	if(f[qs]==1)
	{
		return ;
	}
	f[qs]=1;
	bool dd=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=kn[i];j++)
		{
			if(a[i][j]==qs)
			{
				dd=1;
			}
		}
		if(dd==1)
		{
			for(int j=1;j<=kn[i];j++)
			{
				dfs(a[i][j],zd,s+t[i][j]);
			}
		}
	}
	return ;
}
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
		cin>>kn[i];
		for(int j=1;j<=kn[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		cin>>x>>y;
		cout<<(y-x+1)*t[1][1]+w[x]+w[y]<<endl;
	}
	return 0;
}
