#include<bits/stdc++.h>
using namespace std ;
long long n , a[222222] , l , t , sum , c , f ;
char s[222222] ;
int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout) ;
    cin >> n ;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> a[i] >> s[i] ;//676778917866
    }
    for (int i=1 ; i<=max(n/2, n/2+n%2) and n-i+1!=i ; i++)
    {
        t=n-i+1 ;
        if (s[i]!=s[t])
        {
            if (a[i-1]<a[t+1] and a[t+1]!=0) a[i]-=a[t+1]-a[i-1] ;
            sum+=min(c , a[t]) ;
            if (a[t]-min (a[i] , a[t])==0 and a[i]-a[t]>0)
            {
                c-=a[t] ;
                while (a[i]-a[t]>=0)
                {
                    t-- ;
                    if (a[i]-a[t]<0)
                    {
                        sum+=a[t]-(a[t]-a[i]) ;
                        break ;
                    }
                    sum+=min(a[i] , a[t]) ;
                    a[i]-=a[t] ;
                }
            }

        }
        if (a[i]>a[t])
        {
            a[t-1]-=a[i]-a[t] ;
            sum+=a[i]-a[t] ;
            a[i]=0 ;
            a[t]=0 ;
        }

    }
    cout << sum ;
    return 0 ;
}
