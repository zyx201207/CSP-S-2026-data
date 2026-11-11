#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
const int N=2e5+5;
int n, m;
int a[N];
int vis[N];
int maxx=0;
void check()
{
	int s=0;
	int ans=(1<<21)-1;
	for(int i=1; i<=n; i++)
	{
		if(vis[i]) {ans&=a[i]; s++;}
	}
	if(s==m) maxx=max(maxx, ans);
	return;
}
void dfs(int step)
{
	if(step>n)
	{
		check();
		return;
	}
	vis[step]=1;
	dfs(step+1);
	vis[step]=0;
	dfs(step+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	if(n<=20)
	{
		dfs(1);
	}
	else if(m==1)
	{
		for(int i=1; i<=n; i++) maxx=max(maxx, a[i]);
	}
	else if(m==2)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				maxx=max(maxx, (a[i]&a[j]));
			}
		}
	}
	else if(m==n)
	{
		int ans=(1<<21)-1;
		for(int i=1; i<=n; i++)
		{
			ans&=a[i];
		}
		maxx=ans;
	}
	else
	{
		sort(a+1, a+n+1);
		maxx=a[m];
	}
	cout << maxx;
	return 0;
}
