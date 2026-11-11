#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=10000,inf=1e6;
int m,w[N],n,k[N],t[N][N],a[N][N],d,q,x,y,ans,c,dis[N],fx,fy;
main()
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
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		int px,py;
		for(int j=1;j<=k[i];j++)
		{
			if(a[i][j]==x){
				fx=1;
				px=j;
			}
			if(a[i][j]==y){
				fy=1;
				py=j;
			}
		}
		if(fx==1 && fy==1){
			cout<<w[x]+a[i][px]+a[i][py]+w[y]<<endl;
		}
	}
	return 0;
}
