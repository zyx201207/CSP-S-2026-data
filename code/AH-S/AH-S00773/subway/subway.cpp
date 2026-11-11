#include<bits/stdc++.h>
using namespace std;
long long ccc,n,m,d,q,W[1000000],c,a[1000000],b[1000000],f[505][505];
struct egde
{
	long long t,w;
};
vector<egde>e[100000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ccc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>W[i];
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
			if(i!=j)
				f[i][j]=1e17;
	for(int i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[j]>>b[j];
		for(int j=1;j<k;j++)
			for(int l=j+1;l<=k;l++)
			{
				e[a[j]].push_back({a[l],b[j]+b[l]});
				e[a[l]].push_back({a[j],b[j]+b[l]});
				f[a[j]][a[l]]=f[a[l]][a[j]]=b[j]+b[l];
			}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				f[i][k]=min(f[i][k],f[i][j]+f[j][k]);
	for(int i=1;i<=q;i++)
	{
		long long l,r;
		cin>>l>>r;
		cout<<f[l][r]+W[l]+W[r]<<endl;
	}
	
	return 0;
}


