#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[(int)2e6+5];
ll dis[2005][2005];
ll sum[2005][2005];
void solve()
{
	int n;
	ll d;
	cin>>n>>d;
	ll flag=0;
	int tsxza=1;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		if(i!=1)
		{
			ll tmp=x[i]-x[i-1];
			if(flag==0)flag=tmp;
			else if(flag!=tmp)tsxza=0;
		}
	}
	if(tsxza&&flag!=0)
	{
//		cout<<flag<<' '<<d<<'\n';
		if(flag>d)return cout<<0<<'\n',void();
//		cerr<<"here:"<<'\n';
		ll len=d/flag;
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i+len-1+len<=n&&len>=2)
				ans++;
		}
		cout<<ans<<'\n';
		return;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{			
			sum[i][j]=0;
//			cout<<abs(x[i]-x[j])<<' '<<d<<'\n';
			if(abs(x[i]-x[j])<=d)dis[i][j]=1,sum[i][j]=1;
			else dis[i][j]=4557430888798830399ll;
//			cou
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
					sum[i][j]=sum[i][k]*sum[k][j];
//					cout<<sum[i][j]<<' ';
				}
				else if(dis[i][j]==dis[i][k]+dis[k][j])
				{
//					cout<<sum[i][j]<<' ';
					sum[i][j]+=sum[i][k]*sum[k][j];
				}
			}
		}
	}
	int ans=0;
//	vector<pair<int,int>>p;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(sum[i][j]==2)
			{
//				p.push_back({i,j});
				ans++;
			}
//			cout<<sum[i][j]<<' ';
		}
//		cout<<'\n';
	}
//	for(auto& i:p)
//	{
//		cout<<i.first<<' '<<i.second<<'\n';
//	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
/*
0 1
10 222222222222222208
-999999999999999936 -777777777777777728 -555555555555555520 -333333333333333312 -111111111111111104 111111111111111104 333333333333333312 555555555555555520 777777777777777728 999999999999999936
*/
/*
0 2
5 3
-2 -1 0 1 2
4 2
-4 -3 -2 -1
*/
