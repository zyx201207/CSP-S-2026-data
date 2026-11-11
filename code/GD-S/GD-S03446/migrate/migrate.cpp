#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000010;
int a[N];
int n,d;
int ma,sum;
void dfs(int x,int y,int s)
{
	if(x>y) return;
	if(s>ma) return;
	if(x==y)
	{
		if(s<ma)
		{
			ma=s;
			sum=0;
		}
		if(s==ma)
		{
			sum++;
		}
		return;
	}
	for(int i=y; i>=x+1; --i)
	{
		if(a[i]-a[x]>d) continue;
		dfs(i,y,s+1);
	}
}
bool check(int x,int y)
{
	ma=1e18,sum=0;
	dfs(x,y,0);
//	cerr<<x<<' '<<y<<' '<<ma<<' '<<sum<<'\n';
	if(sum==2) return true;
	return false;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=1; i<=n; ++i) cin>>a[i];
		for(int i=1; i<=n; ++i)
		{
			for(int j=i+1; j<=n; ++j)
			{
				if(a[j]-a[i]<=d) continue;
				if(check(i,j)) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


*/
