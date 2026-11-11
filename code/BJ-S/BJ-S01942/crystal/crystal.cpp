#include <bits/stdc++.h>
using namespace std ;
long long a[500010] ;
struct N{
    long long x ;
    int c ;
}s[500010] ;
int main () {
    freopen("crystal.in" ,"r",stdin) ;
    freopen("crystal.out","w",stdout) ;
    long long m,n ;
    cin >> n >> m ;
    for (int i=1 ; i<=n ; i++){
        cin >> a[i] ;
    }
    sort(a+1,a+n+1) ;
    int j=0 ;
    for (int i=1 ; i<=n ; i++){
        if (s[j].x!=a[i]){
            j++ ;
        }
        s[j].x=a[i] ;
        s[j].c++ ;
    }
    long long maxx=-1000000000010,ans=0 ;
    for (int i=1 ; i<=j ; i++){
        long long t=m ;
        ans=s[i].c ;
        for (int k=i-1 ; k>=1 ; k--){
            if ((s[i].x-s[k].x)*s[k].c>=t){
                ans+=t/(s[i].x-s[k].x) ;
                break ;
            }
            else {
                ans+=s[k].c ;
                t-=(s[i].x-s[k].x)*s[k].c ;
            }
        }
        maxx=max(maxx,ans) ;
    }
    cout << maxx ;
    return 0 ;
}
