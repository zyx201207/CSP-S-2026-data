#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+5,M=5e5+5;
int g[N][N],w[M],a[105][N],t[105][N];
vector<int> mf[M]; 
int dfs(int x,int y)
{
	for(int i=0;i<mf[x].size();i++)
	{
		
	}															
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		
	} 
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dfs(x,y)<<'\n';
	} 
 	return 0;
}





























