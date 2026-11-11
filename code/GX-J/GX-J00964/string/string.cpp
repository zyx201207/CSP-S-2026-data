#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
int n,l,r;
long long ans;
struct dd
{
	int num;
	char flag;
}a[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cin >> n;
	if ( n == 1 )
	{
		cout << 0;
		return 0;
	}
	for ( int i = 1;i <= n;i++ )
	{
		cin >> a[i].num >> a[i].flag;
	}
	l = 1,r = n;
	int t;
	while ( l < r )
	{
		if ( a[l].flag != a[r].flag ){
			ans += min( a[l].num,a[r].num );
		}
		t = a[l].num;
		a[l].num = max ( a[l].num - a[r].num,0 );
		a[r].num = max ( a[r].num - t ,0 );
		if ( a[l].num == 0 )
		    l++;
		if ( a[r].num == 0 )
		    r--;
	}
	cout << ans;
	return 0;
}
