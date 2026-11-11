#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y,mt;
bool b[550];
int p[505][25],t[555];
void dfs(int x,int y){
	b[x]=true;
	for(int i=x;i<=n;i++)
	{
		for(int j=1;j<=d;j++)
		{
			if(p[i][j]==0) break;
			dfs(i,p[i][j],t[p[i][j]]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int p[n+5][d+9],t[m],t2[n+5][d+9];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			p[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>t[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>p[k][j]>>t2[k][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
	 	cin>>x>>y;
	 	dfs(x,y);
	}
	return 0;
}
