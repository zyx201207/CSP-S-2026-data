#include <bits/stdc++.h>
using namespace std;
int n , a ;
char c ;
string str, s[27];
long long ans ;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n ;
    for ( int i = 1 ; i <= 100 ; i++ ) {
        s[1] += "a" ;
        s[2] += "b" ;
        s[3] += "c" ;
        s[4] += "d" ;
        s[5] += "e" ;
        s[6] += "f" ;
        s[7] += "g" ;
        s[8] += "h" ;
        s[9] += "i" ;
        s[10] += "j" ;
        s[11] += "k" ;
        s[12] += "l" ;
        s[13] += "m" ;
        s[14] += "n" ;
        s[15] += "o" ;
        s[16] += "p" ;
        s[17] += "q" ;
        s[18] += "r" ;
        s[19] += "s" ;
        s[20] += "t" ;
        s[21] += "u" ;
        s[22] += "v" ;
        s[23] += "w" ;
        s[24] += "x" ;
        s[25] += "y" ;
        s[26] += "z" ;
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> a >> c ;
        int b = a / 100 ;
        int d = c - 'a' ;
        d++ ;
        for ( int j = 1 ; j <= b ; j++ ) {
            str += s[d] ;
        }
        for ( int j = 1 ; j <= (a % 100) ; j++ ) {
            str += c ;
        }
    }
    int e = str.size() ;
    for ( int i = 0 , j = e - 1 ; i < j ; i++ , j-- ) {
        if ( str[i] != str[j] )
            ans++ ;
    }
    cout << ans ;
    return 0;
}
