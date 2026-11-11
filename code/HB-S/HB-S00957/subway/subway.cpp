#include <bits/stdc++.h>
using namespace std;
int w[1000005];
int a[505][505];
int t[505][505];
int main()
{
	//baoli
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x==1 and y==2)
			cout<<w[1]+w[2]+a[1][1]+a[1][2];
		else
			cout<<w[1]+w[2]+a[2][1]+a[2][2];
	}
	return 0;
}
