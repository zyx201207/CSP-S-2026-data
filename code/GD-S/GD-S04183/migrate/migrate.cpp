#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=305;
int c,T,n,d;
int a[N];
int f[N][N],dis[N][N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>T;
	
	while(T--)
	{
		memset(f,0,sizeof(f));
		memset(dis,0,sizeof(dis));
		cin>>n>>d;
		
		for(int i=1;i<=n;i++) cin>>a[i];
		
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			f[i][i]=1,dis[i][i]=0;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					f[i][j]=1;
					dis[i][j]=1;
					continue;
				}
				
				for(int k=i;k<j;k++)
				{
					if(a[j]-a[k]>d) continue;
					if(a[j]-a[k-1]<=d&&dis[i][k]>dis[i][k-1]) break;
					f[i][j]+=f[i][k];
					dis[i][j]=dis[i][k]+1;
				}
				if(f[i][j]==2) ans++;//,cout<<i<<' '<<j<<'\n';
			}
		}
		
		cout<<ans<<'\n';
	}

	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
