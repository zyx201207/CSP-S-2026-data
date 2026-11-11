#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m,d,q,g[25][1005],dp[1005],w[1005];
bool flag[1005];

struct q
{
	ll id,num;
}t[10005],t1,t2;

void f(ll i)
{
	memset(flag,0,sizeof(flag));
	ll l=1,r=1;
	t1.id=i;
	t1.num=0;
	t[1]=t1;
	while(l<=r)
	{
		if(flag[t[l].id]==0)
		{
			flag[t[l].id]=1;
			for(ll j=1;j<=d;j++)
			{
				if(g[j][l]!=0)
				{
					for(ll k=1;k<=m;k++)
					{
						if(g[j][k]!=0)
						{
							dp[k]=min(dp[k],dp[t[l].id]+g[j][l]+g[j][k]);
							t1.id=k;
							t1.num=dp[k];
							t[++r]=t1;
						}
					}
				}
			}
		}
		l++;
		for(ll j=r;j>l;j--)
		{
			if(t[j].num>t[j-1].num)
			{
				t2.num=t[j].num;
				t2.id=t[j].id;
				t[j].num=t[j-1].num;
				t[j].id=t[j-1].id;
				t[j-1].num=t2.num;
				t[j-1].id=t2.id;
			}
		}
	}
	return;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n;
	cin>>n>>m>>d>>q;
	for(ll i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
	}
	for(ll i=1;i<=n;i++)
	{
		ll k,a,t;
		scanf("%d",&k);
		for(ll j=1;j<=k;j++)
		{
			cin>>a>>t;
			g[i][a]=t;
		}
	}
	for(ll i=1;i<=q;i++)
	{
		ll x,y;
		scanf("%d %d",&x,&y);
		memset(dp,0x3f,sizeof(dp));
		f(x);
		printf("%d\n",dp[y]+w[x]+w[y]);
	}
	return 0;
}
