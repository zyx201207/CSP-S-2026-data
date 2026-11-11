#include <bits/stdc++.h>
using namespace std ;
long long a[5000005] ;
long long cnt[3005] ;
long long pref[3005] ;
int main ()
{
    freopen("card.in","r",stdin) ;
    freopen("card.out","w",stdout) ;
    int m,n ;
    cin >> n >> m ;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> a [i] ;
        cnt[a[i]]++ ;
    }
    pref[1]=cnt[1] ;
    for (int i=2 ; i<=m ; i++)
    {
        pref[i]=pref[i-1]+cnt[i] ;
    }
    for (int i=1 ; i<=m ; i++)
    {
        cout << pref[i]<< " " ;
    }
    return 0 ;
}