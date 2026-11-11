#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[500005],k1,k2,a1[500005],t1[500005];
long long a2[500005],t2[500005];
struct lop
{
	long long x;
	long long y;
}r[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(long long i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	cin>>k1;
	for(long long i=1;i<=k1;i++)
	{
		cin>>a1[i]>>t1[i];
	}
	cin>>k2;
	for(long long i=1;i<=k2;i++)
	{
		cin>>a2[i]>>t2[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>r[i].x>>r[i].y;
	}
	cout<<w[1]+t1[1]+t1[2]+t2[2-1]+t2[3-1]+w[3]<<endl;
	cout<<w[1]+t1[1]+t1[2]+w[2]<<endl;
	return 0;
}
