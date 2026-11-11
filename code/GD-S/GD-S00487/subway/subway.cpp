#include<bits/stdc++.h>
using namespace std;
int n,m,k,q,x,y;
long long d[505][505],w[500005],mi;
struct node{
	int i;
	long long w;
};
vector<node> c[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>x>>n>>m>>y>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)d[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>y;c[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int l=0;l<c[i].size();l++)
		{
			for(int r=l+1;r<c[i].size();r++)
			{
				d[c[i][l].i][c[i][r].i]=min(d[c[i][l].i][c[i][r].i],c[i][l].w+c[i][r].w);
				d[c[i][r].i][c[i][l].i]=min(d[c[i][r].i][c[i][l].i],c[i][l].w+c[i][r].w);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;mi=1e18;
		for(int l=0;l<c[x].size();l++)
		{
			for(int r=0;r<c[y].size();r++)
			{
			    mi=min(mi,d[c[x][l].i][c[y][r].i]+c[x][l].w+c[y][r].w);	
			}
		}
		mi+=w[x]+w[y];
		cout<<mi<<"\n";
	}
	return 0;
}
