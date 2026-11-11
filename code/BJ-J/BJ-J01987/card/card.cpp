#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
const int N1 = 300020;
int ans[N1];
int n, m;
vector < int > a, h;
int main()
{
    freopen( "card.in", "r", stdin );
    freopen( "card.out", "w", stdout );
    cin >> n >> m;
    a.resize( n + 10 );
    h.resize( n + 10 );
    for( int i = 1; i <= n; i++ )
    {
        cin >> a[i];
        h[i] = a[i];
    }
    for( int i = 1; i <= m; i++ )
    {
        cout << i << ' ';
    }
    return 0;
}
