#include<bits/stdc++.h>
using namespace std;
int a[10000][10000],t[10000][10000],w[100000],k[100000],tp[100000],c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		tp[i]=0;

	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{	
			cin>>a[i][j];
			cin>>t[i][j];
			if(tp[a[i][j]]==0)
			tp[a[i][j]]=t[i][j];
			
		}
	}
	
	

	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+tp[x]+tp[y]<<"\n";
	}
		
	
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2                               buhuixie
*/

