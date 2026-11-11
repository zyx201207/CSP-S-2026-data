#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10;
long long c,t,n,d,x[N];
long long check(long long u,long long v)
{
	if(u==v)return 0;
	for(long long i=v;i>u;i--)
	{
		if(x[i]-x[u]<=d)return 1+check(i,v);
	}
	return -1;
}
long long bl(long long u,long long v,long long mb,long long step)
{
	if(u==v&&mb==step)return 1;
	if(step>=mb)return 0;
	long long ans=0;
	for(long long i=v;i>u;i--)
	{
		if(x[i]-x[u]<=d)ans+=bl(i,v,mb,step+1);
		if(ans>2)break;
	}
	return ans;
}
void solve()
{
	cin>>n>>d;
	long long ans=0;
	for(long long i=1;i<=n;i++)cin>>x[i];
	for(long long u=1;u<=n-3;u++)
	{
		for(long long v=u+3;v<=n;v++)
		{
			long long mb=check(u,v);
			if(mb!=-1)
			{
				if(bl(u,v,mb,0)==2)ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
