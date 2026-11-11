#include <bits/stdc++.h>
using namespace std;
#define int long long
int n , m , a[200005] ;
vector<int>v1[200005],v2[40];
int xxx(int k,int now)
{
	if (now<0)return 0;
	for ( int i = now ; i >= 0 ; i -- )
		v2[i].clear();
	for ( int i = 1 ; i <= k ; i ++ )
		for ( auto j : v1[i] )
		{
			if (j>now)break;
			v2[j].push_back(i);
		}
	for ( int i = now ; i >= 0 ; i -- )
		if (v2[i].size()>=m)
		{
			for ( int j = 1 ; j <= v2[i].size() ; j ++ )
				swap(v1[j],v1[v2[i][j-1]]);
			return (1<<i)+xxx(v2[i].size(),i-1);
		}
	return 0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> a[i] ;
		for ( int j = 0 ; j <= 29 ; j ++ )
			if (a[i]&(1<<j))
				v1[i].push_back(j);
	}
	cout << xxx(n,29) ;
	return 0;
}
