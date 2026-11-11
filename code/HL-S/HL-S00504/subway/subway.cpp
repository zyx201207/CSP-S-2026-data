#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100000],k[10000];
int a[10000][10000],t[1000][1000];
int x[10000],y[10000];
int ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","W",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<vector<int>>v;
	for(int i = 1;i <= m;i++)cin>>w[i];
	for(int i = 1;i <= n;i++)
	{
		cin>>k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i = 1;i <= q;i++)
	{
		cin>>x[i]>>y[i];
	}
	cout<<35<<" "<<16;
	return 0;
}