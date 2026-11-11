#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int E=2e5+5;
int maxx=INT_MIN;
int n,m;
int a[E];
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int step,int sum,int cnt)
{
	if(cnt>m) return ;
	if(step>n)
	{
		if(cnt==m)
			maxx=max(maxx,sum);
		return ;
	}
	dfs(step+1,(sum&a[step]),cnt+1);
	dfs(step+1,sum,cnt);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	dfs(1,a[1],0);
	cout<<maxx;
	return 0;
}

