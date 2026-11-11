#include<bits/stdc++.h>

using namespace std;

void init()
{
    freopen( "crystal.in" , "r" , stdin );
    freopen( "crystal.out" , "w" , stdout );
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
long long a[500010] , m;
long long sum[500010];

inline bool check( int x )
{
    int l = 1 , r = x;
    long long now = sum[r];
    while ( r <= n )
    {
        if ( ( r - l + 1 ) * a[r] - now <= m )
            return 1;
        now -= a[l];
        l++;
        r++;
        now += a[r];
    }
    return 0;
}

int main()
{
    init();
    cin >> n >> m;
    for ( int i = 1 ; i <= n ; i++ )
        cin >> a[i];
    sort( a + 1 , a + n + 1 );
    for ( int i = 1 ; i <= n ; i++ )
        sum[i] = sum[i - 1] + a[i];
    int l = 1 , r = n;
    while ( l <= r )
    {
        int mid = l + r >> 1;
        if ( check( mid ) )
            l = mid + 1;
        else r = mid - 1;
    }
    cout << l - 1 << endl;
    return 0;
}