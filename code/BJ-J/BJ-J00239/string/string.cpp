#include <bits/stdc++.h>
using namespace std ;
long long n , a , xb = 0 , cnt ;
char c ;
char s[2000000000] ;
int main()
{
    freopen("string.in","r",stdin) ;
    freopen("string.out","w",stdout) ;
    cin >> n ;
    while(n--) {
        cin >> a >> c ;
        int xxb = xb + a ;
        for(int i = xb + 1 ; i <= xxb ; i++){
            s[i] = c ;
        }
        xb =xxb ;
    }
    int j = xb ;
    for(int i = 1 ; i < j ; i++)
    {
        if(s[i] != s[j]) cnt++ ;
        j-- ;
    }
    cout << cnt ;
    return 0 ;
}
