#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int w[N];
int h[2][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int i,j,k;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)	
		cin>>w[i];
	for(i=1;i<=2;i++)
	{
		cin>>k;
		for(j=1;j<=2*k;j++)
			cin>>h[i][j];
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
	}
	return 0;
} 
