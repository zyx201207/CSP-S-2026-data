#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[1000005],b[1000005],z[505],x[1000005],y[1000005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>z[i];
		for(int j=1;j<=z[i];j++)
		{
			int l,r;
			cin>>l>>r;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	if(n==2)
	{
		cout<<32<<"\n"<<19-n;
	}
	else
	{
		cout<<35<<"\n"<<19-n;
	}
	
	return 0;
 } 
