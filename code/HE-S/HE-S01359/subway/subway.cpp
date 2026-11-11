#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[10003],v[10003],y[10004];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k*2;j++)
		{
			cin>>v[i]>>y[i];
		}
		cout<<w[1]+w[2]+y[1]+y[2]<<"/n";
	}
	return 0;
}
