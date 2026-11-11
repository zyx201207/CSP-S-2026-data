#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		long long ans=0;
		int a[maxn]={},x[maxn][maxn]={};
		bool f[maxn][maxn]={};
		cin>>n>>d;
		for(int i = 1;i <= n;i++) cin>>a[i];
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				if(abs(x[i]-x[j]) <= d) f[i][j]=true;
			}
			for(int j = i+1;j <= n;j++)
			{
				for(int k = j+1;k <= n;k++)
				{
					if(f[i][j]==true&&f[j][k]==true) x[i][j]++;
				}
			}
			for(int j = 1;j <= n;j++)
			{
				if(x[i][j]==2) ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
