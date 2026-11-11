#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int c,n,m,d,q,w[N],k[1001],x,y,u,v[501][N],t[501][N];
vector<int>o[1001]; 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>v[i][j]>>t[i][j];
			o[v[i][j]].push_back(i);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y],z=INT_MAX;
		for(int j=0;j<o[x].size();j++)
		{
			bool xx,yy;
			u=0;
			for(int b=1;b<=k[o[x][j]];b++)
			{
				if(v[o[x][j]][b]==x)
					u+=t[o[x][j]][b],xx=1;
				if(v[o[x][j]][b]==y)
					u+=t[o[x][j]][b],yy=1;
			}
			if(xx && yy)
				z=min(u,z);
		}
		cout<<ans+z<<"\n";
	}
	return 0;
}/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/ 
