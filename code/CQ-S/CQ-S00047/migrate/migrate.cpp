#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll t,n,d,ls[50005],cnt;

struct p
{
	ll id,cnt;
};

bool f(ll x,ll y)
{
	queue<p> q;
	ll cnt;
	p t2;
	t2.cnt=0;
	t2.id=x;
	q.push(t2);
	while(!q.empty())
	{
		p t=q.front();
		for(ll i=t.id;i<=y;i++)
		{
			if(ls[i]-ls[t.id]<=d)
			{
				if(i==y)
				{
					cnt++;
				}
				t2.id=i;
				t2.cnt=t.cnt+1;
				q.push(t2);
			}
		}
	}
	return cnt==2;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;
	cin>>t;
	while(t--)
	{
		scanf("%d %d",&n,&d);
		for(ll i=1;i<=n;i++)
		{
			scanf("%d",&ls[i]);
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+3;j<=n;j++)
			{
				if(f(i,j))
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
