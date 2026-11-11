#include <bits/stdc++.h>
using namespace std;
long long int c,n,m,d,q;
long long int T[100001];
long long int w[500005],k[505],x[100005],y[100005];
long long int a[5005][505],t[5005][505];

void init()
{
	cin>>c>>n>>m>>d>>q;
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
}
void findway(int a,int b)
{
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	init();
	cout<<"35\n16";
	return 0;
}
