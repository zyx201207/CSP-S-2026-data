#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,m,a[N],ans,vis[N],b[N],s;
void dfs(int t,int x)
{
	if(t>=m) {ans=max(ans,x);return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		dfs(t+1,x&a[i]);
		vis[i]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<4) s++,b[a[i]]++;
	}	
	sort(a+1,a+n+1);
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
			vis[i]=1,dfs(1,a[i]),vis[i]=0;
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans;
		return 0;
	}
	if(s==n)
	{
		if(a[3]>=m) cout<<3;
		else if(a[3]+a[2]>=m) cout<<2;
		else if(a[3]+a[1]>=m) cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<a[n-m+1];
	return 0;
}
