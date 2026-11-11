#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000005],cnt,maxn;
priority_queue<int,vector<int>,greater<int> > q;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
		q.push(a[i]);
	}
	if(m==1)
	{
		cout<<q.top();
		return 0;
	}
	
	if(m==n)
	{
		cnt=a[1]&a[2];
		for(int i=3;i<=n;i++) cnt=(cnt&a[i]);
		cout<<cnt;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn=max(maxn,(a[i]&a[j]));
				
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1)
	{
		for(int i=2;i<=n;i++)
		{
			cnt=a[i-1]&a[i+1];
			for(int j=2;j<=n;j++)
			{
				if(j!=i)
				{
					cnt=(cnt&a[j]);
				}
			}
			maxn=max(maxn,cnt);
		}
		cout<<maxn;
		return 0;
	}
	cout<<q.top();
	return 0;
}
/*
6
5
2
7
15
31
63
127
*/
