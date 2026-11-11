#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],used[N],n,m,ans,pre[N],s[N];
void dfs(int x,int cnt)
{
	if(x>n)
	{
		if(cnt!=m) return;
		int sum,fl=0;
		for(int i=1;i<=n;i++)
		{
			if(used[i]&&!fl) sum=a[i],fl=1;
			else if(used[i]) sum&=a[i];
		}
		ans=max(ans,sum);
		return;
	}
	if(cnt>m) return;
	used[x]=0;
	dfs(x+1,cnt);
	used[x]=1;
	dfs(x+1,cnt+1);
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int maxx=0,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		//minn=min(minn,a[i]);
		if(i==1) sum=a[i];
		else sum&=a[i];
	}
	if(n<=20)
	{
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	else if(m==1) cout<<maxx;
	else if(m==n) cout<<sum;
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
	}
	else if(m==n-1)
	{
		s[1]=a[1],pre[n]=a[n];
		for(int i=2;i<=n;i++) s[i]=s[i-1]&a[i];
		for(int i=n-1;i>=1;i--) pre[i]=pre[i+1]&a[i];
		maxx=max(pre[2],s[n-1]);
		for(int i=2;i<n;i++) maxx=max(maxx,s[i-1]&pre[i+1]);
		cout<<maxx;
	}
	else 
	{
		sort(a+1,a+n+1,greater<int>());
		ans=a[1];
		for(int i=2;i<=m;i++) ans&=a[i];
		cout<<ans;
	}
	return 0;
}
