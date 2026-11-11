//8
#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005];
long long a[505][500005];
vector<long long> had[500005];
long long find(long long x,long long y)
{
	return x+y;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		for(int j=1;j<=k;k++)
		{
			int aa,tt;
			cin>>aa>>tt;
			a[i][aa]=tt;
			had[aa].push_back(i);
		}
	}
	if(n==2)
	{
		long long hc=1e9+7;
		for(int i=1;i<=m;i++)
			if(a[1][i] && a[2][i])
				hc=min(hc,a[1][i]+a[2][i]);
		for(int i=1;i<=q;i++)
		{
			int x,y,xx=0,yy=0;
			cin>>x>>y;
			if((a[1][x] && a[1][y]) || (a[2][x] && a[2][y]))
			{
				cout<<w[x]+w[y]<<endl;
				continue;
			}
			else
				cout<<w[x]+w[y]+hc;
		}
		return 0;
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<find(x,y)+w[x]+w[y]<<endl;
	}
	return 0;
}
