#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using pii=pair<int,int>;
int a[200010],st[200010],t[200100];
int pows(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b%2!=0) ans*=a;
		b/=2;
		a*=a;
	}
	return ans;
}
int n,m,ans=-INF;
void dfs(int x,int cnt,int sum)
{
	if(x==n+1) return ;
	if(cnt==m)
	{
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(st[i]==1) continue;
		st[i]=1;
		dfs(x+1,cnt+1,sum&a[i]);
		st[i]=0;
		dfs(x+1,cnt,sum);
	}
}
bool cmp(int x,int y)
{
	return x>y;
}
bool is(int x)
{
	for(int i=0;i<=20;i++)
	{
		if(x==pows(2,i)-1) return 1;
	}
	return 0;
}
bool iss(int x)
{
	for(int i=0;i<=20;i++)
	{
		if(x==pows(2,i)) return 1;
	}
	return 0;
}
signed main()
{
	freopen("and4.in","r",stdin);
	freopen("and4.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool ok=true,okk=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(is(a[i])==0) ok=false;
		if(a[i]!=i-1) okk=false;
	}
	if(n<=20)
	{
		dfs(1,0,pows(2,30)-1);
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		ans=pows(2,30)-1;
		for(int i=1;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(ok==true)
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	if(okk==true&&iss(n)==1)
	{
		cout<<n-m;
		return 0;
	}
	for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	cout<<ans;
	return 0;
}
