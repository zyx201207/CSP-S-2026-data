#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long res=0,f=1;
	char x=getchar();
	while(!isdigit(x))
	{
		if(x=='-')f=-1;
		x=getchar();
	}
	while(isdigit(x))
	{
		res=(res<<1)+(res<<3)+(x^48); 
		x=getchar();
	}
	return res*f;
}
const int N=2e6+5;
long long c,t,n,d,a[N];
vector<long long> v[N];
queue<int> q;
long long dis[N],cnt[N],ans;
void dij(int x)
{
	q.push(x);
	for(int i=1;i<=n;i++)dis[i]=2e18+1,cnt[i]=0;
	dis[x]=0;cnt[x]=1;
	while(!q.empty())
	{
		x=q.front();q.pop();
		for(auto i:v[x])
			if(dis[i]==dis[x]+1)cnt[i]+=cnt[x];
			else if(dis[i]>dis[x]+1)dis[i]=dis[x]+1,cnt[i]=cnt[x],q.push(i);
	}
}
void solve()
{
	n=read();d=read();ans=0;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<n&&a[j+1]<=a[i]+d)j++;
		for(int k=i+1;k<=j;k++)
			v[i].push_back(k);
	}
	for(int i=1;i<=n;i++)
	{
		dij(i);
		for(int j=1;j<=n;j++)
			if(cnt[j]==2)ans++;
	}
	for(int i=1;i<=n;i++)v[i].clear();
	printf("%d\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--)solve();
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

0 1
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000
*/
