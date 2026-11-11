#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5000+10;
ll Read()
{
	ll res=0;
	int c=getchar(),flag=1;
	for(;!isdigit(c);c=getchar()) if(c=='-') flag=-1;
	for(;isdigit(c);c=getchar()) res=res*10+(c^48);
	return res*flag;
}
int C,T;
int n;
ll d,a[N];
ll ans;
void solve1()
{
	if(n==1)
	{
		cout<<0<<'\n';
		return;
	}
	ll tmp=d/(a[2]-a[1]);
	if(tmp<=1||n<tmp+tmp)
	{
		cout<<0<<'\n';
		return;
	}
	cout<<n-tmp-tmp+1<<'\n';
}
ll dist[N];
ll cnt[N];
void dfs(int now)
{
	if(now>n) return;
	for(int i=now+1;i<=n;i++)
	{
		if(dist[i]==0) dist[i]=dist[now]+1;
		if(a[i]-a[now]<=d)
		{
			if(dist[i]==dist[now]+1) cnt[i]+=cnt[now];
			else if(dist[i]>dist[now]+1)
			{
				dist[i]=dist[now]+1;
				cnt[i]=cnt[now];
			}
		}
		else break;
	}
	dfs(now+1);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=Read(); T=Read();
	while(T--)
	{
		n=Read(); d=Read();
		ans=0;
		for(int i=1;i<=n;i++) a[i]=Read();
		if(C>=11&&C<=12)
		{
			solve1();
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			memset(cnt,0,sizeof(cnt));
			memset(dist,0,sizeof(dist));
			cnt[i]=1;
			dfs(i);
			for(int j=i+1;j<=n;j++)
				if(cnt[j]==2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
