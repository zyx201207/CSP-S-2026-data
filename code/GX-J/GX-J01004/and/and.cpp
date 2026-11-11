#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n , m , a[1000000] , s , t;
    cin >> n >> m;
    for( int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        s = a[i] and a[i+1];
        t = a[i] and a[i+2];
        if( s >= t)
        {
            cout << s;
        }
        else
        {
            cout << t;
        }
    }
    return 0;
}
