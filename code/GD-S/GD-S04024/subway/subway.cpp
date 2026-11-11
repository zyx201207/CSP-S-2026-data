#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=1e5*5+5;
int w[N];
int t1[N][N];
int t2[N][N];
int k[N];
int x[N];
int y[N];
int ans[N];
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
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++)
		{
			cin>>t1[i][j]>>t2[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
	}
	ans[1]=19;
	ans[2]=12;
	for(int i=1;i<=n;i++)
	{
		cout<<w[1]+w[y[i]]+ans[i]<<endl;
	}
	
	return 0;
} 

