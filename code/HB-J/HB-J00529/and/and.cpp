#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5 + 9;
int n,m;
int a[N];
int ans;
int mx;

void dfs(int p , int sum,int cnt)
{
	if(cnt > m)
	{
		ans = max(sum,ans);
		return ;
	}
	if(p > n) return ;
	dfs(p + 1,sum & a[p],cnt + 1);
	dfs(p + 1, sum, cnt);
}

int main()
{
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		mx = max(a[i],mx);
	} 
	
	if(n <= 20)
	{
		int t = pow(2,19);
		dfs(1,t - 1,1);
		cout << ans;
	}
	else if(m == 1)
	{
		cout << mx;
	}
	else if(m == 2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int sum = a[i] & a[j];
				ans = max(sum,ans);
			}
		}
		cout << ans;
	}
	else
	{
		int t = a[1];
		sort(a+1,a+1+n,greater<int>());
		for(int i=1;i<=m;i++){
			t &= a[i];
		}
		cout << t;
	}
	return 0;
}
