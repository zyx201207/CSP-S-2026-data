#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,d,q,k[N],w[N],x[1e5+10],y[1e5+10],C;
vector<int>a[510];
vector<int>t[510];
int main()
{
	freopen("subway.in","r",stdin);
 	freopen("subway.out","w",stdout);
	cin >>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++)
	{
		
	}
	return 0;
 } 
