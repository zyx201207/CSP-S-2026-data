#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> to[1005];
int a[2000005];
int f[2005][2005],s[2005][2005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
			to[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(abs(a[i]-a[j])<=d)
				{
					to[i].push_back(j);
					to[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) f[i][j]=0;
				else f[i][j]=1e9;
				s[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<(int)(to[i].size());j++)
			{
				f[i][to[i][j]]=1;
//				cout<<i<<' '<<j<<' '<<to[i][j]<<" =1"<<endl;
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i==k||j==k||+i==j||f[i][k]==1e9||f[k][j]==1e9) continue;
					if(f[i][j]==f[i][k]+f[k][j])
					{
						s[i][j]++;
//						cout<<f[i][j]<<" "<<f[i][k]+f[k][j]<<' '<<i<<' '<<j<<endl;
					}
					if(f[i][j]>f[i][k]+f[k][j])
					{
						s[i][j]=1;
//						cout<<f[i][k]<<' '<<f[k][j]<<' '<<i<<' '<<j<<' '<<k<<endl;
					}
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(s[i][j]==2) ans++;
//				cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
			}
		}
		cout<<ans/2<<endl;
	}
	return 0;
}
