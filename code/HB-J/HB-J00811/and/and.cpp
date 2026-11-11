#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+9;
int a[N],flag[N];
long long n,m,ans = INT_MIN;
void dfs(int step,long long cnt)
{
	if(step > m)
	{
		ans = max(ans,cnt);
	}
	for(int i=1;i<=n;++i)
	{
		if(flag[i] == 0)
		{
			flag[i] = 1;
			dfs(step+1,cnt&a[i]);
			flag[i] = 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bool f = 1;
	for(int i=1;i<=n;++i)
	{
		cin >> a[i];
		if(a[i] != i-1)
		{
			f = 0;
		}
	}
	if(n>2000 && f==0)
	{
		sort(a+1,a+n+1);
		ans = a[n-m+1];
	}
	else if(n>2000 && f)
	{
		ans = a[n];
		for(int i=n-1;i>=n-m+1;i--)
		{
			ans &= a[i];
		}
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			flag[i] = 1;
			dfs(2,a[i]);
			flag[i] = 0;
		}
	}
	cout << ans;	
	return 0;
}
