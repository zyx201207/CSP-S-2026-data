#include<bits/stdc++.h>
using namespace std;
long long m,n,d,p,b[505][505],a[500005],k,w[500005],v[500005],z,y,ans=0,l,ll;
int c;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
    	for(long long i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			cin>>y;
			cin>>b[y][i];
		}
	}
	for(long long i=1;i<=p;i++)
	{
		cin>>w[i];
		cin>>v[i];
	}
	for(long long i=1;i<=p;i++)
	{
		for(int j=1;j<=n;j++) ans=b[j][1]+ans;
		l=w[i];
		ll=v[i];
		cout<<ans+a[l]+a[ll]<<endl;
	}
	return 0;
 } 
