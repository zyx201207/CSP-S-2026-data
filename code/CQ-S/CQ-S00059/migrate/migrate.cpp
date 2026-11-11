#include<bits/stdc++.h>
using namespace std;
const int N=1e4+3;
long long x[N];
long long cs[N][N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int C,T;
	cin>>C>>T;
	for(int t=1;t<=T;t++)
	{
		long long ans=0;
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int len=1;len<=n;len++)
		{
			for(int i=1;i+len<=n;i++)
			{
				int j=len+i;
				if(x[j]-x[i]<=d)
				{
					cs[i][j]=1;
					continue;
				}
				if(len==1&&x[j]-x[i]>d)
				{
					n=i;
					continue;
				}
				cs[i][j]=cs[i][i+1]+cs[i+1][j];
				for(int k=i+2;k<j;k++)
				{
					cs[i][j]=min(cs[i][k]+cs[k][j],cs[i][j]);
				}
				long long js=0;
				for(int k=i+1;k<j;k++)
				{
					if(cs[i][k]+cs[k][j]==cs[i][j])
					{
						js++;
					}
				}
				//cerr<<js<<' ';
				if(js==2)
				{
					ans++;
				}
			}
		}
		//cerr<<'\n'<<'\n'<<ans<<'\n'<<'\n';
		cout<<ans<<'\n';
	}
	return 0;
}
