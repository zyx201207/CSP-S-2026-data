#include <bits/stdc++.h> 
using namespace std;
long long n,m,c[5*100005],cnt[5*100005];
long long ok[5*100005];
long long zm[5*100005],zmn,cn;
void xg()
{
	long long x=ok[c[cn]];
	for(int i=x+1;i<=zmn-1;i++)ok[zm[i]]=0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n==m)
	{
		for(int i=1;i<=n;i++)cout<<i<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		long long a=n-i+1;
		zm[n+5],zmn=i,cn=i;
		memset(ok,0,sizeof(ok));
		while(a--)
		{
			if(ok[c[cn]]!=0)xg(),zmn=ok[c[cn]];
			else ok[c[cn]]=zmn,zm[zmn]=c[cn];
			zmn++;
			cn++;
		}
		for(int j=i;j<zmn;j++)
		{
			cnt[zm[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}
