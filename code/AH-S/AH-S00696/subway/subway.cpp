#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,wl[505],l,r;
long long k[505],a[505][505],b[505][505],sum;
struct node{
	long long v,w;
};
vector<node>g[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>wl[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>b[i][j];	
			b[i][j]=b[j][i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			long long x=a[i][j],y=a[i][j-1];
			g[x].push_back({y,b[x][y]});
			g[y].push_back({x,b[y][x]});
		}
	}
	while(q--)
	{
		cin>>l>>r;
		sum=0;
		sum=sum+wl[l]+wl[r];
		cout<<sum+b[l][r]<<endl;
	}
	return 0;
}
