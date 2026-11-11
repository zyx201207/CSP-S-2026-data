#include <iostream>
using namespace std;

int main(){
    freopen("string.in" , "r" , stdin) ;
    freopen("string.out" , "w" , stdout) ;
    int n ;
    int a[100005] ;
    char c[100005] ;
    string cnt = "" ;
    cin >> n ;
    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i] >> c[i] ;
        for (int j = 1 ; j <= a[i] ; j ++)
        {
            cnt += c[i] ;
        }
    }
    long long ans = 0 ;
    long long l = 0 , r = (cnt.size())-1 ;
    while (l <= r)
    {
        if (cnt[l] != cnt[r])
        {
            ans ++ ;
            cnt[r] = cnt[l] ;
        }
        l ++ ;
        r -- ;
    }
    cout << ans ;
    return 0;
}
