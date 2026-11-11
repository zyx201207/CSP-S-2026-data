#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
typedef long long LL;
LL n,m;
int lef;
int a[500010];
LL c[500010],powerc[500010];
int ans;

inline int lowbit( int x ) {    return x & (-x); }
void add( int x,int k ){for ( int i = k;i <= n;i += lowbit( i ) ){c[i] += x;}}
void addpower( LL x,int k ){for ( int i = k;i <= n;i += lowbit( i ) ){powerc[i] += x;}}
LL query( int x ){
	LL sum = 0;
	for ( int i = x;i;i -= lowbit( i ) ){sum += c[i];}
	return sum;
}
LL powerquery( int x ){
	LL sum = 0;
	for ( int i = x;i;i -= lowbit( i ) ){
		sum += powerc[i];
		sum++;
	}
	sum--;
	return sum;
}

bool check( int l,int r )
{
	if ( powerquery( r ) - powerquery( l ) <= m )
	{
		return 1;
	}
	return 0;
}
int solve( int L,int R,int pos )
{
	while ( L < R )
	{
		int mid = (L + R + 1)/ 2;
		if ( check( mid,pos ) )
		{
			R = mid - 1;
		}
		else
		    L = mid;
    }
    return L;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    cin >> n >> m;
    for ( int i = 1;i <= n;i++ ){cin >> a[i];}
	sort ( a + 1,a + n + 1 );
	for ( int i = 2;i <= n;i++ )
    {
		add( abs( a[i] - a[i - 1] ),i );
	}
	for ( int i = 1;i <= n;i++ )
    {
		LL sum = query( i );
		addpower( sum,i ); 
		if ( a[i] == a[i - 1] ){powerc[i + 1] += sum + i;powerc[i] = powerquery( i-1 );}
		//powerc[i] = powerc[i - 1] + i * ( a[i] - a[i - 1] );
		/*if ( a[i] != a[i - 1] )
			addpower( sum,i );
		else
		    powerc[i] = powerquery( i-1 );
		if ( a[i - 1] == a[i - 2] )
			powerc[i] += i - 1;*/
	}
	//for ( int i = 1;i <= n;i++ ){cout << powerquery( i ) << '\n';}
	for ( int r = 2;r <= n;r++ )
	{
	//	lef = upper_bound( powerc + 1,powerc + r + 1,m ) - c - 1;
		lef = solve( 1,r,r );
		int i = r + 1;
		while ( a[i] == a[r] )
		    i++;
		i--;
//		if( i-lef + 1 > ans ){cout << "asasd" << lef << " " << i << " ";	cout << powerquery( i ) - powerquery( lef ) << '\n';}
		ans = max ( {ans,1,i-lef + 1 } );
		//r = i + 1;
	}
	cout << ans;
    return 0;
}
