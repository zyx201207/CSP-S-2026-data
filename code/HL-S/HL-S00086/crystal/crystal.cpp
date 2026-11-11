#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    int m;
    cin >> n >> m;
    int a[n];
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    sort( a , a + n );
    while( m )
    {
        a[ 0 ]++;
        m--;
        sort( a , a + n );
    }
    int ans;
    int cnt = 1;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[ i ] == a[ i + 1 ])
        {
            cnt++;
            if ( ans < cnt ) ans = cnt;
        }
        else
        {

            if ( ans < cnt ) ans = cnt;
            cnt = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
