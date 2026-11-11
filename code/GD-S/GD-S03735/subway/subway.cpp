#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,f;
long long w[500005];
long long k[600],a[505][500005],t[505][500005];
int main()
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%lld%lld",&a[i][j],&t[i][j]);
	}
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",f);
	}
	return 0;
} 
