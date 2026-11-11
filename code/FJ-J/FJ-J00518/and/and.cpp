#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,vis[200005],cn0[200005];
void dfs(int k,int sum)
{
	if(k>1&&sum<=ans) return ;
	if(k==m+1)
	{
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			if(k==1) dfs(k+1,a[i]);
			else dfs(k+1,(sum&a[i]));
			vis[i]=0;
		}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	else if(m==2)
	{
		int cnt=0;
		for(int i=1;i<=31;i++)
			for(int j=i+1;j<=31;j++) cnt=max(cnt,a[i]&a[j]);
		cout<<cnt;
		return 0;
	}
	else if(m==n)
	{
		int cnt=a[1];
		for(int i=2;i<=n;i++) cnt&=a[i];
		cout<<cnt;
		return 0;
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			bitset<32> num(a[i]);
			cn0[i]=num.size()-num.count();
		}
		int id=0,cnt;
		for(int i=1;i<=n;i++) if(cn0[id]<cn0[i]) id=i;
		if(id==1)
		{
			cnt=a[2];
			for(int i=3;i<=n;i++) cnt&=a[i];
		}
		else
		{
			cnt=a[1];
			for(int i=2;i<=n;i++) cnt&=a[i];
		}
		cout<<cnt;
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=n;i++) if(a[n-i+1]!=i-1) flag=0;
	if(flag)
	{
		int cnt=a[1];
		for(int i=2;i<=m;i++) cnt&=a[i];
		cout<<cnt;
		return 0;
	}
	else if(n<=20)
	{
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	else 
	{
		cout<<a[m];
		return 0;
	}
	return 0;
}
