#include <bits/stdc++.h>
using namespace std;
long long a[100010];
int n,m;
long long ans =0 ;
void dfs(long long i,long long cnt,long long num)
{
	if(i > n) return;
	if(num >= m)
	{
		ans = max(cnt,ans);
		return;
	}
	dfs(i+1,cnt,num);
	if(cnt == 0 && num == 0) cnt = a[i];
	cnt = cnt&a[i];
	dfs(i+1,cnt,num+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1 ; i <= n ; i ++) cin >> a[i];
	dfs(1,0,0);
	cout << ans;
}
