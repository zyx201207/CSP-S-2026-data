#include <bits/stdc++.h>
using namespace std;
const int N=2000005;
long long c,t;
long long n,d;
long long a[N];
long long cnt;
long long tmp;
long long ans;
void dfs(long long x,long long y,long long num)
{
	if(x==y)
	{
		if(num==tmp)cnt++;
		else if(num<tmp)
		{
			tmp=num;
			cnt=0;
		}
		return;
	}
	for(long long i=x+1;i<=y;i++)
	{
		if(a[i]-a[x]<=d)dfs(i,y,num+1);
		else break;
	}
	return;
}
void clear()
{
	ans=0;
	memset(a,0,sizeof(a));
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(long long i=1;i<=n;i++)cin>>a[i];
		for(long long i=1;i<=n-2;i++)
		{
			for(long long j=i+2;j<=n;j++)
			{
				tmp=0x3f3f3f3f3f3f3f3f;
				cnt=0;
				dfs(i,j,0);
				ans+=cnt;
			}
		}
		cout<<ans<<'\n';
		clear();
	}
	return 0;
}
