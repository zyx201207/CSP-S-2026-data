#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+20;
ll c,t,i,j,n,d,de[N],a[N];
bool f[N];
ll bfs(ll u,ll v)
{
	queue<ll> q;
	q.push(u);
	f[u]=true;
	bool fl=false;
	ll sum=0,mi;
	while(!q.empty())
	{
		ll t=q.front();
		q.pop();
		if(t==v)
		{
			if(!fl)
			{
				fl=true;
				mi=de[t];
				sum++;
//				cout<<"114514:"<<mi<<"\n";
			}
			else if(de[t]==mi)
			{
				sum++;
			}
			
			continue;
		}
		ll i;
		for(i=1;i<=n;i++)
		{
			if(!f[i]&&abs(a[i]-a[t])<=d)
			{
				de[i]=de[t]+1;
				q.push(i);
				f[i]=(i==v?false:true);
			}
		}
	}
	return sum*(sum-1)/2;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		ll ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				ans+=bfs(i,j);
				memset(f,false,sizeof(f));
				for(ll kk=1;kk<=n;kk++)
				{
					de[kk]=0;
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
