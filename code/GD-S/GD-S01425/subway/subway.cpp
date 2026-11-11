#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,w[500005],k[505];
struct node
{
	long long a,t;
}x[505];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>x[i].a>>x[i].t;
	}
	for(long long i=1;i<=q;i++)
	{
		long long X,Y;
		cin>>X>>Y;
		cout<<w[X]+w[Y]+2*x[1].t;
	} 
	
	return 0; 
}
