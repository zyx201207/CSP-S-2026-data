#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],ans=1;
int d[2000005],num[2000005];
void dij(int yy)
{
	queue<int> q;
	q.push(yy);
	while(q.size())
	{
		int x=q.front();
		q.pop();
		for(int i=x+1;i<=n;i++)
		{
			if(a[i]-a[x]>m)break;
			if(d[x]+1<d[i])
			{
				d[i]=d[x]+1;
				num[i]=num[x];
				q.push(i);
			}
			else if(d[x]+1==d[i])
			{
				d[i]=d[x]+1;
				num[i]++;
			}
		}
	}
	
}
void solve()
{
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i;j<=n;j++)
		{
			d[j]=1e9+114514;
			num[j]=0;
		}
		d[i]=0;
		num[i]=1;
		dij(i);
		for(int j=i;j<=n;j++)
		{
//			cout<<i<<" -> "<<j<<" : "<<d[j]<<" roads: "<<num[j]<<"\n";
			if(num[j]==2)ans++;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
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

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
//Oct31==Dec25?
//finish at 16:54
