#include <bits/stdc++.h>
using namespace std;
int m,n,c,q,o;
struct way
{
	int to,len;
};
int d[500005],a[500005],x[500005],y[500005];
bool f[500005];
vector <way> v[500005];
void dijcstra(int s)
{
	memset(f,0,sizeof(f));
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	for(int i=1;i<=m;i++)
	{
		int mi=-1;
		for(int j=1;j<=m;j++)
		{
			if(!f[j]&&(mi==-1||d[j]<d[mi]))
			{
				mi=j;
			}
			
			
		}
		f[mi]=1;
		for(int j=0;j<v[mi].size();j++)
		{
			int to=v[mi][j].to,l=v[mi][j].len;
			if(!f[to]&&d[mi]+l<d[to])
			{
				d[to]=d[mi]+l;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>o>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			
			cin>>x[j]>>y[j];
			
		}
		for(int j=1;j<=k;j++)
		{
			for(int p=j+1;p<=k;p++)
			{
				v[x[j]].push_back({x[p],y[j]+y[p]});
				v[x[p]].push_back({x[j],y[j]+y[p]});
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		dijcstra(l);
		cout<<d[r]+a[l]+a[r]<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
