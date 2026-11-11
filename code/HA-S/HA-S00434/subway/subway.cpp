#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
using namespace std;
int n,m,d,q,w[586],a[586][5086],t[586][5086];
vector<pii>g[500086];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=2*k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		int x,y,sum=0;
		cin>>x>>y;
		sum+=w[x]+w[y];
		for(int i=1;i<x;i++)
		{
			for(int j=1;j<=y;j++) sum+=t[i][j];
		}
		cout<<sum<<'\n';
	}
	return 0;
}
