#include <bits/stdc++.h>
using namespace std;
const int N = 500020;
long long a[N];//每颗水晶的能量
long long n, m;
long long crr;//水晶需要增加的能量总数
int maxc = -1;//最多有多少个水晶能量值相等
int main()
{
    freopen( "crystal.in", "r", stdin );
    freopen( "crystal.out", "w", stdout );
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a[i];
    }
    sort( a + 1, a + n + 1 );
    for( long long i = 2; i <= n; i++ )
    {
        while( a[i] == a[i + 1] )
        {
            i++;
        }
        for( long long j = 1; j <= i; j++ )//求如果有a[i]个水晶的能量相等最少需要花费多少能量
        {
            crr += abs(a[i] - a[j]);
        }
        if( crr < m )
        {
            maxc = i;
            crr = 0;
        }
        else if( crr == m )
        {
            maxc = i;
            break;
        }
        else{
            break;
        }
    }
    cout << maxc;
    return 0;
}
