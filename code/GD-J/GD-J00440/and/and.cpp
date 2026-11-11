#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],num[200010][40],flag,ss,tj[40],ans;
void turnn(long long val,long long xb)
{
	long long i=1;
	while (val>0)
	{
		num[xb][i]=val%2;
		flag=max(flag,i);
		i++;
		val/=2;
	}
	return ;
}
long long powerr(long long shu,long long c)
{
	if (c==0)
	{
		return 1;
	}
	long long shu1=shu;
	for (long long i=1;i<=c-1;i++)
	{
		shu*=shu1;
	} 
	return shu;
}
bool cmp (long long x,long long y)
{
	return x>y;
}
deque<long long>dq;
void bfs(long long xb)
{
	if (xb==n+1)
	{
		long long len=dq.size(),ji=0,cnt=0;
		if (len!=m)
		{
			return ;
		}
		for (long long i=1;i<=flag;i++)
		{
			ji=0;
			for (long long j=0;j<=len-1;j++)
			{
				if (num[dq[j]][i]==0)
				{
					ji=1;
					break;
				}
			}
			if (ji==0)
			{
				cnt+=powerr(2,i-1);
			}
		}
		if (cnt>=ans)
		{
			ans=cnt;
		}
		return ;
	}
	bfs(xb+1);
	dq.push_back(xb);
	bfs(xb+1);
	dq.pop_back();
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for (long long i=1;i<=n;i++)
	{
		turnn(a[i],i);
	}
	bfs(1);
	cout<<ans;
}
