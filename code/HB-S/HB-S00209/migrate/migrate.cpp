#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000001],b,l=1,r=1,ans=0;
struct edge{
	long long ti,pl;
};
long long duan(long long u,long long v)
{
	if(a[v]-a[u]<=d)return 1;
	long long now=u,next=u,cnt=0;
	while(next<=v)
	{
	    while(a[next]-a[now]<=d&&next<=n)
	    {
	    	next++;
	    }
	    now=next-1;
	    next=now;
	    cnt++; 
	}
	return cnt;
}
long long bfs(long long u,long long v,long long b)//b=duan(u,v)
{
	edge q[2000001];
	long long cnt=0;
	r++;
	q[r].ti=0;
	q[r].pl=u;
	while(l==r)
	{
		long long p=q[l].pl;
		long long t1=q[l].ti;
		l++;
		for(long long i=p+1;i<=v;i++)
		{
			if(t1+1==b&&i==v)
			{
				cnt++;
				break;
			}
			if(a[i]-a[p]<=d&&t1+1<=b)
			{
				q[r].ti=t1+1;
				q[r].pl=i;
			}
		}
	}
	return cnt;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
		scanf("%lld%lld",&n,&d);
		for(long long j=1;j<=n;j++)
		{
			scanf("%lld",&a[j]);
		}
		for(long long i1=1;i1<n;i1++)
		{
			for(long long j1=i1+1;j1<=n;j1++)
			{
				b=duan(i1,j1);
				if(bfs(i1,j1,b)==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
    return 0;
}
