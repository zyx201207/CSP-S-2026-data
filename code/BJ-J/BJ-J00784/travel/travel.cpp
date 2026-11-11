#include <bits/stdc++.h>
using namespace std ;

bool f[10] ;

int main()
{
    freopen("travel.in" , "r" , stdin) ;
    freopen("travel.out" , "w" , stdout) ;
    string c1 , s1 , c2 , s2 ;
    cin >> c1 >> s1 >> c2 >> s2 ;

    string ans = "" ;
    if(c1 == c2)    
        ans = ans + "1" ;
    else
        ans = ans + "0" ;
    
    string a , b ;
    a = s1[0] + s1[1] ;
    b = s2[0] + s2[1] ;

    if(c1 == c2 && a == b)
        ans = ans + "1" ;
    else
        ans = ans + "0" ;

    f[s1[2] - 'A' + 1] = 1 ;
    f[s2[2] - 'A' + 1] = 1 ;
    if(c1 == c2 && a == b && ((s1[2] - 'A' + 1 <= 3 && s2[2] - 'A' + 1 <= 3) || (s1[2] - 'A' + 1 >= 4 && s2[2] - 'A' + 1 >= 4)))
        ans = ans + "1" ;
    else
        ans = ans + "0" ;
    
    bool F = 0 ;
    for(int i = 2 ; i <= 5 ; i ++)
    {
        if(ans == "111" && f[i] == 1 && f[i - 1] == 1)
            ans = ans + "1" , F = 1 ;
    }
    if(!F)
        ans = ans + "0" ;

    cout << ans << endl;
    return 0 ;
}