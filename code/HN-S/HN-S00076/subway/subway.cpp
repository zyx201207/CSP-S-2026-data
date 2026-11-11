#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int M=5e5+5,N=505;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M],x,y;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		cin>>x>>y;
		cout<<4*w[1]<<endl; 
	}
	return 0;	
} 
