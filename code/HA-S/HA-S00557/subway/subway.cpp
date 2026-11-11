#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=1e5*5+10;
const int inf=0x3f3f3f3f;
int w[N],a[510][N],check[N];
long long dis[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for (int j=1;j<=k;j++) 
		{
			int x,y;cin>>x>>y;
			a[i][x]=y;
			a[x][i]=y;
		}
	}
	while (q--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=0;
		memset(dis,inf,sizeof(dis));
		memset(check,0,sizeof(check));
		dis[x]=0;
		for (int i=1;i<=n;i++)
		{
			int minn=inf,pos=0;
			for (int j=1;j<=n;j++)
			{
				if (dis[j]<minn&&check[j]==0)
				{
					minn=dis[j];
					pos=j;
				}
			}
		}
	}
	
	return 0;
}
