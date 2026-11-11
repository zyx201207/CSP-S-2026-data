#include<bits/stdc++.h>
using namespace std;
long long questar[1000000],queend[1000000];
long long x[1000][10000],t[10000][10000];
long long a[66666666];
long long c,n,m,p,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>p>>q;
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
			cin>>x[i][j]>>t[i][j];
		}			
	}
	for(int i=1;i<=q;i++)
	{
		cin>>questar[i]>>queend[i];
	}
	for(int i=1;i<=q;i++)
	{
		int sum=0;
		sum+=a[questar[i]];
		sum+=a[queend[i]];
		sum+=t[1][questar[i]];
		sum+=t[2][queend[i]];
		cout<<sum<<endl;
	}
}
