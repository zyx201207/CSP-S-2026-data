#include<bits/stdc++.h>
using namespace std;
struct sub
{
	long long z;
	long long t;
};
sub kt[11133][11133];
long long c,n,m,d,q,zs,ans,zs1;
long long w[500005],x[500005],y[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >> zs;
		zs1+=zs;
		for(int j=1;j<=zs;j++)
		{
			cin >> kt[i][j].z >> kt[i][j].t;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin >> x[i] >> y[i];
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		ans+=w[x[i]]+w[y[i]];
		
		cout << ans << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
