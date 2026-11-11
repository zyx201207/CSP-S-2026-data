#include<bits/stdc++.h>
using namespace std;
int x[100005],y[100005],m,w[505],k[500005],a[505][500005],n,c,d,q,t[505][500005],ju,tt[505][20005],sum[100005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			if(j==1)continue;
			tt[a[i][j]][a[i][j-1]]=tt[a[i][j]][a[i][j-1]]+t[i][j-1];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++)cout<<sum[i]<<endl;
	return 0;
}
