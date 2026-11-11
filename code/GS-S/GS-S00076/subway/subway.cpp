#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[502],a[502][50005],t[502][50005],x,y,bs;
//并查集!!!
long long faw[500005];//最头 
long long find(long long x);//找头 
{
	if(fa[x]!=x)
	{
		return find(fa[x]);
	}
	return x;
}
void u(long long x,long long y);
{
	fa[find(y)]=find(x);
}
bool pd(long long x,long long y)
{
	if(find(x)==find(y))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		faw[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<k[i];j++)
		{
			u(a[j],a[j+1]);
		}
	}
	
	for(int i=1;i<=q;i++)
	{
		bs=0;
		cin>>x>>y;
		long long xx,yy;
		if(pd(x,y)==1)
		{
			bs+=w[x]+w[y];
			
			cout<<bs<<endl;
		}
	}
	return 0;
}
