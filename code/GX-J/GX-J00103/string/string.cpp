#include <bits/stdc++.h>
#include <string>
using namespace std ;

int main ()
{
    freopen ("string.in" , "r" , stdin) ;
    freopen ("string.out" , "w" , stdout) ;

    int n ;
    cin >> n ;

    long long a [n] = {} ;
    char c [n] = {} ;

    long long ans = 0 , num = 0 ;

    for (int i = 0 ; i < n ; ++ i)
    {
        cin >> a [i] >> c [i] ;
        num = num + a [i] ;
    }

    for (long long i = 0 ; i <= num - i - 1 ; ++ i)
    {
        char c1 = ' ' , c2 = ' ' ;
        long long l1 = -1 , l2 = num - 1 ;
        for (int ii = 0 ; ii < n ; ++ ii)
        {
            l1 = l1 + a [ii] ;
            l2 = l2 - a [n - ii - 1] ;
            if (c1 == ' ' && i <= l1)
            {
                c1 = c [ii] ;
                //cout << "l1 = " << l1 << " i = " << i << endl ;
            }
            if (c2 == ' ' && num - i - 1 > l2)
            {
                c2 = c [n - ii - 1] ;
                //cout << "l2 = " << l2 << " i = " << i << " num - i - 1 = " << num - i - 1 << endl ;
            }
            if (c1 != ' ' && c2 != ' ')
            {
                break ;
            }
        }

        //cout << c1 << " " << c2 << endl ;

        if (c1 != c2)
        {
            ++ ans ;
        }
    }

    cout << ans ;

    return 0 ;
}
