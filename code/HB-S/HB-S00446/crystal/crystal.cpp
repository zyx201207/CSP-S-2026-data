#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000005],k,flag,t,ans,book[1000005],cnt;
priority_queue<int,vector<int>,greater<int> > q;
signed main()
{ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	k=a[2]-a[1]; 
	for(int i=3;i<=n;i++) 
	{
		if(a[i]-a[i-1]!=k) flag=1;
		k=a[i]-a[i-1];
	}
	if(k<0) k=-k;
	if(flag==0)
	{
		while(m-t*k>=0&&ans<=n-1)
		{
			t++;
			m-=t*k;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	if(flag==1)
	{
		for(int i=2;i<=n;i++) q.push(abs(a[i]-a[i-1]));
		while(q.size())
		{
			book[++cnt]=q.top();
			q.pop();
		}
		while(m-book[t]*t>=0&&ans<=n)
		{
			t++;
			m-=book[t]*t;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
