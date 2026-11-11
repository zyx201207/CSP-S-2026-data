# include <bits/stdc++.h>
using namespace std;
long long n , m , s[200605] , cnt , cnt1 , ans1 , ans2;
void dfs(long long x , int num , int id)
{
	if(num > m) 
	{
		ans1 = max(x , ans1);
		return;
	}
	if(num==m)ans1=max(x,ans1);
	for(int i = id + 1; i <= n; i ++)
	 dfs(x&s[i],num+1,i);
}
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
    	cin >> s[i];
	}
	if(n < 20)
	{
		if(m == 1)
		 for(int i = 1; i <= n; i ++)
		  ans1 = max(ans1 , s[i]);
		if(m == 2)
		 for(int i = 1; i <= n; i ++)
		  for(int j = i + 1; j <= n; j ++)
		    ans1 = max(s[i]&s[j] , ans1);
		if(m == n)
		  for(int i=2,ans=s[1];i<=n;i++)
		   ans&=s[i] , ans1 = ans;
		   else
		for(int i = 1; i <= n; i ++)
		dfs(s[i],1,i);
		cout << ans1;
	}
	else
	{
		if(m == 1)
		 for(int i = 1; i <= n; i ++)
		  ans1 = max(ans1 , s[i]);
		if(m == 2)
		 for(int i = 1; i <= n; i ++)
		  for(int j = 1; j <= n; j ++)
		    ans1 = max(s[i]&s[j] , ans1);
		if(m == n)
		  for(int i=2,ans=s[1];i<=n;i++)
		   ans&=s[i] , ans1 = ans;
		   cout<<ans1;
	}
}