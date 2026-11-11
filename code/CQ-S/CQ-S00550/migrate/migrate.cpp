#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
const int N=2e6+5;
lo C,T,n,d,a[N],f[N],dis[N],cnt[N];
queue<lo>q;
void solve()
{
	cin>>n>>d;lo res=0;
	for(lo i=1;i<=n;i++)cin>>a[i];
	bool fl=1;
	for(lo i=3;i<=n;i++)fl&=(a[i]-a[i-1]==a[2]-a[1]);
	for(lo i=1;i<=n;i++)
	{
		lo l=i,r=n,mid=0;f[i]=i;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(a[mid]-a[i]<=d)l=(f[i]=mid)+1;
			else r=mid-1;
		}
	}
	for(lo i=1;i<=n;i++)
	{
		for(lo j=i;j<=n;j++)dis[j]=1e18,cnt[j]=0;
		q.push(i);dis[i]=0;cnt[i]=1;
		while(q.size())
		{
			lo u=q.front();q.pop();
			for(lo v=u+1;v<=f[u];v++)
			{
				if(!cnt[v])cnt[v]=cnt[u],dis[v]=dis[u]+1,q.push(v);
				else if(dis[u]+1==dis[v])cnt[v]+=cnt[u];
			}
		}
		for(lo j=i+1;j<=n;j++)res+=(cnt[j]==2);
	}
	cout<<res<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;while(T--)solve();
}
/*
bfs 的全称……是啥来着？

可以成对当且仅当距离可以被唯一拆解成两个小于等于 d 的数

我是啥子啊……怎么才想到 写不完了 
*/
