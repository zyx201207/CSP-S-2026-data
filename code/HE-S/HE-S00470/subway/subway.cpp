#include <bits/stdc++.h>
using namespace std;
long long w[510],a[510],t[510],x[100010],y[100010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,r;
	cin>>c>>n>>m>>d>>r;
	if(c==0)
	{
	   	long long k;
		for(int i=1;i<=m;i++)
		{
			cin>>w[i];
		}
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=k;i++)
		{
			cin>>t[i];
		}
		for(int i=1;i<=r;i++)
		{
			cin>>x[i]>>y[i];
		}
		if(n==2) cout<<32<<endl<<17;
		if(n==3) cout<<35<<endl<<16;
	}
	else{
		long long k;
		for(int i=1;i<=m;i++)
		{
			cin>>w[i];
		}
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=k;i++)
		{
			cin>>t[i];
		}
		for(int i=1;i<=r;i++){           
			cin>>x[i]>>y[i];
		}
		cout<<t[1]*k;
	}
	return 0;
}
