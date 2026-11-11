#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int n , m;
long long dfs( long long ans , int l , int d )
{
	if ( d == 0 )
		return 0x7f7f7f7f;
	long long c = 0;
	for ( int i = l ; i + d - 1 <= n ; i ++ )
	{
		if ( m == d )
			c = max(c,a[i]&dfs(a[i],i+1,d-1));
		else
			c = max(c,ans&a[i]&dfs(ans&a[i],i+1,d-1));
	}
	return c;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for ( int i = 1 ; i <= n ; i ++ )
		cin >> a[i];
	cout << dfs(0,1,m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
