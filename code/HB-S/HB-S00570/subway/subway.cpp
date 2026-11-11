#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500010];
int k[510];
long long t[510][20010];
int x[100010],y[100010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
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
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	
	return 0;
}

