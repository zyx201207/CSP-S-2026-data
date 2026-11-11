#include <bits/stdc++.h>
using namespace std;
struct dijstl
{
	long long num,c[500005],hz,lx[500005];
}f[500005];
long long m,n,w[500005],a[500005],t[500005],q,sbw,start,endd,kn,d,first;
bool bz[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>sbw>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>kn;
		for(long long j=1;j<=kn;j++)
		{
			cin>>a[j]>>t[a[j]];
		}
		for(long long j=1;j<kn;j++)
		{
			for(long long k=j+1;k<=kn;k++)
			{
				f[a[j]].num++;
				f[a[j]].c[f[a[j]].num]=t[a[k]]+t[a[j]];
				f[a[j]].lx[f[a[j]].num]=a[k];
				f[a[k]].num++;
				f[a[k]].c[f[a[k]].num]=t[a[k]]+t[a[j]];
				f[a[k]].lx[f[a[k]].num]=a[j];
			}
		}
	}
	for(long long i=1;i<=q;i++)
	{
		cin>>start>>endd;
		fill(bz,bz+m+1,0);
		first=start;
		for(long long j=0;j<=m;j++)
		{
			f[j].hz=1e12;
		}
		f[start].hz=0;
		for(long long k=1;k<=m;k++)
		{
			long long jj=1e12;
			for(long long j=1;j<=m;j++)
			{
				if(bz[j])
				{
					continue;
				}
				if(f[j].hz<=jj)
				{
					start=j;
					jj=f[j].hz;
				}
			}
			bz[start]=1;
			for(long long j=1;j<=f[start].num;j++)
			{
				if(bz[f[start].lx[j]])continue;
				f[f[start].lx[j]].hz=min(f[start].hz+f[start].c[j],f[f[start].lx[j]].hz);
			}
		}
		cout<<f[endd].hz+w[first]+w[endd]<<endl;
	}
	return 0;
}
