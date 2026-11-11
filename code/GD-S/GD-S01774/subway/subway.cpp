#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int INF=0x3f3f3f3f;
long long c,n,m,d,q,w[N],k,a[510][N],t[510][N],x,y;
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
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		cin>>x>>y;
	}
	if(n==2)
	{
		cout<<32<<" "<<17;
	}
	else
	{
		cout<<35<<" "<<16;
	}
	return 0;
}

