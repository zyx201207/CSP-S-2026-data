#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int w[N],a[205][205],t[205][205],x[100005],y[100005],k[205];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;++i)
	{
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++)
	{
		cin>>x[r]>>y[r];
	}
	for(int r=1;r<=q;r++)
	{
		long long time=0;
		time+=(w[x[r]]+w[y[r]]);
		cout<<time<<"\n";
	}
	
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/ 
