#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
/*inline int lowbit( int x ){    return x & (-x); }
void add( int x,int k )
{
	for ( int i = x;i <= n;i += lowbit( i ) )
	{
		c[i] = k;
	}
}
int query( int x )
{
	for ( int i = n;i >= 1;i -= lowbit( i ) )
	{
		if ( c[i] == x )
		    return i;
	}
	return 0;
}
bool cmp( dd x,dd y )
{
	if ( x.num != y.num )
	{
		return x.num < y.num;
	}
	return x.p < y.p;
}
* 10 3
* 3 1 2 1 3 2 3 1 2 1
* */
int n,m;
int a[500010];
long long ans[300010];
int pos[500010];
map<int,int>mp;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	cin >> n >> m;
	for ( int i = 1;i <= n;i++ )
	{
		cin >> a[i];
		//ans[a[i]]++;
		if ( mp.count( a[i] ) )
		{
			pos[mp[a[i]]] = i;
		}
		mp[a[i]] = i;
	}
	if ( m == 1 )
	{
		cout << n;
		return 0;
	}
	
	
	if ( m == 2 )
	{
		int tiao1 = 0,tiao2 = 0;
		for ( int i = n;i >= 1;i-- )
		{
			if ( a[i] == 1 )
			    tiao1 = i;
			if ( a[i] == 2 )
			    tiao2 = i;
			if ( tiao1 && tiao2 )
			    break;
		}
		for ( int l = 1;l <= n;l++ )// ju shu   pos shi dang qian wei zhi tiao dao de xia yi ge wei zhi
		{
			for ( int i = l;i <= n;i++ )
			{
				if ( a[i] == 1 )
				    i = tiao1;
				if ( a[i] == 2 )
				    i = tiao2;
				ans[a[i]]++;
			}
		}
		cout << ans[1] << " " << ans[2];
		return 0;
	}
	
	
	//for ( int i = 1;i <= n;i++ ){
		//cout << a[i] << " "<< pos[i] << "\n";}
    for ( int l = 1;l <= n;l++ )// ju shu   pos shi dang qian wei zhi tiao dao de xia yi ge wei zhi
    {
		for ( int i = l;i <= n;i++ )
		{
			while ( pos[i] > i )
			{
				i = pos[i];
			}
			ans[a[i]]++ ;
		}
	}
	for ( int i = 1;i <= m;i++ )
	{
		cout << ans[i] << " ";
	}
	return 0;
}
