#include <bits/stdc++.h> 
using namespace std;
int w[500005];
int k[500005];
int a[500005],b[500005],c[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int e=1;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=e;j<=x;j++)
		{
			cin>>a[j];
			cin>>a[j+x];
		}
		e=(i+1)*x+1;
	}
	e=1;
	for(int i=1;i<=q;i++)
	{
		cin>>b[e]>>b[e+1];
		e+=q;
	}
	e=1;
	for(int i=1;i<=q;i++)
	{
		for(int i=1;i<=b[e+1]i++)
		{
			
		}
		
	}
	return 0;
}
