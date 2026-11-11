#include <bits/stdc++.h>
using namespace std ;
int a[1000005] ;
int maxn ;
int cnt[5] ;
bool cmp(int a,int b)
{
    return a>b ;
}
int main ()
{
    freopen("and.in","r",stdin) ;
    freopen("and.out","w",stdout) ;
    int n,m ;
    cin >> n >> m ;
    if(m==1)
    {
        int maxn=0 ;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> a[i] ;
            maxn=max(maxn,a[i]) ;
        }
        cout << maxn ;
    }
    else
    {
        for (int i=1 ; i<=n ; i++)
        {
            cin >> a[i] ;
            maxn=max(maxn,a[i]) ;
        }
        if (maxn<4)
        {
            for (int i=1 ; i<=n;  i++)
            {
                cnt[a[i]]++ ;
            }
            if (m-cnt[3]<=0)
            {
                cout << 3 ;
            }
            else if (m-cnt[3]-cnt[2]<=0)
            {
                cout << 2 ;
            }
            else
                cout << 1 ;
        }
        else
        {
            sort(a+1,a+n+1,cmp) ;
            cout << a[m] ;
        }
    }
    return 0 ;
}
