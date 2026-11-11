#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010;
int c,T,n,d,a[N],f[N][N],dis[N][N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>T;
	while(T--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++)cin>>a[i];
		for(int i=1; i<=n; i++)for(int j=1; j<=n; j++)f[i][j]=dis[i][j]=0;
		for(int i=n,x=n; i; i--)
		{
			while(a[x]-a[i]>d)x--;
			for(int j=i+1; j<=x; j++)f[i][j]=dis[i][j]=1;
			for(int j=x+1; j<=n; j++)
			{
				f[i][j]=f[x][j],dis[i][j]=dis[x][j]+1;
				for(int k=x-1; k>i; k--)
				{
					if(f[i][j]>2||dis[k][j]+1>dis[i][j])break;
					f[i][j]+=f[k][j];
				}
				ans+=(f[i][j]==2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
