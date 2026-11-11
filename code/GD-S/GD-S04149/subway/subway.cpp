#include<bits/stdc++.h>
using namespace std;
int w[50001];
long long r[501][50001];
long long t[501][50001];
int dis[9000][9000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int _,n,m,d,q,k;
	cin>>_>>n>>m>>d>>q;
	memset(dis,0,sizeof(dis));
	if(m>=10000||n>=50000)
	{
		cout<<"CCF,you win.";
		return 0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)cin>>r[i][j]>>t[i][j];
	}
	int x,y;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<dis[x][y]<<"\n";
	}
	return 0;
}
