#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll t,n,d,x[2000009],ans,c;
void dfs(ll yx,ll k,ll &sum,ll now)
{
	if(yx==k)
	{
		sum++;
		return;
	}
	for(int o=now;o<=n;o++)
	{
		dfs(yx+1,k,sum,now+1);
		return;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		ll sum=1;
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(x[2]-x[1]>d)
		{
			cout<<"0"<<endl;
			continue;
		}
		ll diff=x[2]-x[1];
		ll maxfd=d/diff;
		for(ll i=2;i<=maxfd;i++)
		{
			dfs(0,i,sum,1);
			if(sum==2)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

