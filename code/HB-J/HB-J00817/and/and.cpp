#include <bits/stdc++.h>
using namespace std;
int n,m;
long long maxn=-1,sum,maxx=-1;
long long ac[200005];
bool book[200005];
void dfs(long long x,long long step)
{
	if(step==m)
	{
		maxx=max(maxx,x);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(book[i]==1) continue;
		book[i]=1;
		dfs(x&ac[i],step+1);
		book[i]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>ac[1];
	sum=ac[1];
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&ac[i]);
		sum=sum&ac[i];
		maxn=max(maxn,ac[i]);
	}
	if(m==1) cout<<maxn;
	else if(m==n) cout<<sum;
	else if(m==2)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,ac[i]&ac[j]);
			}
		}
		cout<<ans;
	}
	else
	{
		dfs(ac[1],0);
		cout<<maxx;
	}
	return 0;
}
