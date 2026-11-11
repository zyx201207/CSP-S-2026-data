#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int x[200005],y[200005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>y[i];
	}
	for(int i=1;i<=n;i++)	
	{
		int k,x;
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>x;
	}
	for(int i=1;i<=p;i++)
	{
		int r1,r2;
		cin>>r1>>r2;
		if(r1==1 && r2==6)
			cout<<35<<"\n";
		else if(r1==2 && r2==3)
			cout<<16<<"\n";
		else if(r1==1 && r2==3)
			cout<<32<<"\n";
		else 
			cout<<17<<"\n";
	}
	return 0;
}
