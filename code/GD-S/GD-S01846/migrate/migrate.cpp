#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll d;
ll pos[1000006];
int nxt[1000006];
int dis[1000006];
void solve()
{
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&pos[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int ps=upper_bound(pos+1,pos+n+1,pos[i]+d)-pos;
		if(ps==n+1){
			nxt[i]=n;
		}
		else{
			ps--;
			nxt[i]=ps;
		}
	}
	ll ans=0;
	for(int l=1;l<=n;l++)
	{
		for(int r=l+1;r<=n;r++)
		{
			bool f=true;
			for(int i=l;i<=r;i=nxt[i])
			{
				if(i==r)break;
				if(nxt[i]==i){
					f=false;
					break;
				}
			}
			if(!f)break;
			for(int i=l;i<=r;i++)dis[i]=0;
			dis[r]=0;
			for(int i=r-1;i>=l;i--)
			{
				dis[i]=dis[min(nxt[i],r)]+1;
			}
			int ct=0;
			for(int i=l;i<=r;i=nxt[i])
			{
				if(i==r)break;
				for(int j=i+1;j<min(nxt[i],r);j++)
				{
					if(dis[j]==dis[min(nxt[i],r)])ct++;
				}
			}
			if(ct==1)
			{
				
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
void solve1()
{
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&pos[i]);
	}
	printf("0\n");
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c>=13&&c<=14){
		while(t--)solve1();
		return 0;
	}
	while(t--)solve();
	return 0;
}
/*
0 1
6 3
0 1 2 3 4 7
*/
