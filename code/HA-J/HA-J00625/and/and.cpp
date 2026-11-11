#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[200100];
long long s[200100];
long long ppp()
{
	long long cnt;
	cnt=s[0]&s[1];
	for(long long i=2;i<m;i++)
	{
		cnt=cnt&s[i];
	}
	return cnt;
}
void dfs(long long x,long long d)
{
	
	if(d==m)
	{
		for(long long i=0;i<d;i++)
		{
			ans=max(ppp(),ans);
		}
	}
	
	for(long long i=x+1;i<=n;i++)
	{
 		s[d]=a[i];
		dfs(i,d+1);
		
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	
	return 0;
}
