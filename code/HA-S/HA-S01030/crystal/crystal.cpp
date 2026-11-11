#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int check(int mid)
{
	int sum=0,ans=0;
	priority_queue<int>q;
	
	for(int i=1;i<=n;i++)
	{
		if(a[i]<mid)
		{
			if(sum>m && !q.empty())
			{
				if(mid-a[i]<q.top())
				sum-=q.top();
				q.pop();
				sum+=mid-a[i];
				if(sum<=m)ans++;
				q.push(mid-a[i]);
			}
			else
			{
				sum+=mid-a[i];
			if(sum<=m)ans++;
			q.push(mid-a[i]);
			}
			
		}
		if(a[i]==mid)ans++;
	}
	return ans;
}
signed main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin.tie(0),cout.tie(0);

	cin>>n>>m;
	priority_queue<int>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	int maxn=1;
	while(l<r)
	{
		int mid=(l+r)/2;
		int qwq=check(a[mid]);
		if(qwq>1)
		{
			l=mid+1;
			if(qwq>maxn)maxn=qwq;
		}
		else r=mid;
	}
	cout<<maxn;
	return 0;
}

