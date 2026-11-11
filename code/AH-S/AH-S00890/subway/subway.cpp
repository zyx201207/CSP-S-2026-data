#include<bits/stdc++.h>
using namespace std;
int lj[10005][10005]={0};
int c,n,m,d,q,k[505],a[505][50005],t[505][50005],w[500005];
int dijstra(int l,int r)
{
	long long dist[50005];
	memset(dist,1e8,sizeof(dist));
	dist[l]=0;
	for(int i=l;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(lj[i][j])
			{
				dist[j]=min(dist[j],dist[i]+lj[i][j]);
			}
		}
	}
	return dist[r];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			if(j!=1)
			{
				lj[a[i][j]][a[i][j-1]]=t[i][j]+t[i][j-1];
				lj[a[i][j-1]][a[i][j]]=t[i][j]+t[i][j-1];
			}
		}
		lj[a[i][1]][a[i][k[i]]]=t[i][1]+t[i][k[i]];
		lj[a[i][k[i]]][a[i][1]]=t[i][1]+t[i][k[i]];
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<lj[i][j]<<"											";
//		}
//		cout<<'\n';
//	}
	int l,r;
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		if(l>r)swap(l,r);
		long long ans;
		ans=dijstra(l,r)+w[l]+w[r];
		cout<<ans<<'\n';
	}
	return 0;
}
