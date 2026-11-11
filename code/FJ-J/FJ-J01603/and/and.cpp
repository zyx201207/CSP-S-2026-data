#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,maxx,a[N],s[N];
bool vis[N];
void dfs(int x,int step)
{
	if(step>=m)
	{
		maxx=max(maxx,x);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(x&a[i],step+1);
			vis[i]=0;
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		s[i]=s[i-1]&a[i];
	}
	if(n==m)
	{
		cout<<s[n];
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		dfs(a[i],0);
	}
	cout<<maxx;





	return 0;
}

