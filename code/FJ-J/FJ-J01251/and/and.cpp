#include <bits/stdc++.h>
using namespace std;

int n,m;
const int MAXN=2e5+5;
long long a[MAXN];
long long ans;
bool dis[200005];

void dfs(long long sum,int num)
{
	if(num==m)
	{
		ans=max(sum,ans);
		return ;
	}
	
	for(int i=1;i<=n;++i)
	{
		if(sum==0)
		{
			sum=a[i];
			dis[i]=1;
			dfs(sum,++num);
			dis[i]=0;
		}
		if(!dis[i])
		{
			dis[i]=1;
			dfs(sum&=a[i],++num);
			dis[i]=0;
		}else
		{
			continue;
		}
	}
	
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	ans=a[n];
	if(m==1)
	{
		cout<<ans<<'\n';
		return 0;
	}else
	{
		dfs(0,0);
		cout<<ans<<'\n';
		return 0;	
	}
} 
