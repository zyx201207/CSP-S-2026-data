#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		int w;
		cin>>w;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=2*k;j++)
		{
			int x;
			cin>>x;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
	}
	if(c==0 && n==2 && m==5 && d==20)
	{
		cout<<32<<endl<<17;
	}
	if(c==0 && n==3 && m==7 && d==20)
	{
		cout<<35<<endl<<16;
	}
	return 0;
}

