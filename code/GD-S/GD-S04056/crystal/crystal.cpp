#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n,m;
int a[maxn];
int sum[maxn];
struct cdq
{
	priority_queue<int> q,dq;
	void del(int x)
	{
		dq.push(x);
		while(dq.size()&&dq.top()==q.top())
		{
			dq.pop();q.pop();
		}
	}
	void push(int x)
	{
		q.push(x);
	}
	int top()
	{
		return q.top();
	}
}q;
signed main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		q.push(a[i]);
		if(q.top()*(i-l+1)-(sum[i]-sum[l-1])>m)
		{
			q.del(a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
}
