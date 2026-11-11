#include <bits/stdc++.h>
using namespace std ;

int main ()
{
    freopen ("and.in" , "r" , stdin) ;
    freopen ("and.out" , "w" , stdout) ;

    int n , m ;
    cin >> n >> m ;

    int l [n] = {} ;
    int c [n] [2] = {} ;
    int d [31] = {} ;
    d [0] = 1 ;
    long long ans = 0 ;

    /*
    for (int i = 0 ; i < n ; ++ i)
    {
        cin >> l [i] ;
    }
    for (int i = 1 ; i < 31 ; ++ i)
    {
        d [i] = d [i - 1] * 2 ;
    }

    for (int i = 0 ; i < n ; ++ i)
    {
        for (int ii = 0 ; ii < i ; ++ ii)
        {
            if (c [ii] > c [ii + 1])
            {
                swap (c [ii] , c [ii + 1]) ;
            }
        }
    }

    for (int i = 0 ; i < n ; ++ i)
    {
        for (int ii = 1 ; ii < 31 ; ++ ii)
        {
            if (l [i] < d [ii] && l [i] >= d [ii - 1])
            {
                c [i] [0] = d [ii] ;
                c [i] [1] = d [ii] - l [i] ;
            }
        }
    }

    for (int i = n - 1 ; i >= 0 ; ++ i)
    {
        int h = c [i] [0] ;
        for (int )
    }
    */
    ans = l [0] & l [1] ;
    for (int i = 2 ; i < m ; ++ i)
    {
        ans = ans & l [i + 1] ;
    }

    cout << ans ;

    return 0 ;
}
