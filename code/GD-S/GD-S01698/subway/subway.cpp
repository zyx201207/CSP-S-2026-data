#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int a[505][100005],t[100005],w[100005];
	for(int i=1;i<=m;i++)
	{
	cin>>w[i];
	}
	map<int,int>p;
	int k[100005];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[j];
		}
	}
	int x[q+1],y[q+1];
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		cout<<w[x[i]]+w[y[i]]*2;
	}

}
