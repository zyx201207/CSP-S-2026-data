#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 5e5 + 400 ;
ll a[N], qz[N] ;int n;
ll m;
signed main()
{
    freopen("crystal.in", "r", stdin) ;
    freopen("crystal.out", "w", stdout) ;
    cin.tie(0) ;
    cout.tie(0) ;
    ios::sync_with_stdio(0) ;
    cin>>n>>m ;
    for(int i=1;i<=n;++i)  
    {
        cin>>a[i] ;
        // qz[i] = qz[i-1] + a[i] ;
    }
    int t = 0;
    sort(a+1, a+1+n) ;
    for(int i=1;i<=n;++i)
        qz[i] = qz[i-1] + a[i] ;
    for(int i=1;i<=n;i++)
    {
        int l1 = 0, r1 = i ;
        while(l1 < r1)
        {
            int mid = l1+r1>>1;
            if((i - mid) * a[i] - qz[i] + qz[mid]<= m) r1 =mid ;
            else l1 = mid + 1;
        }
        t = max(t, i - l1) ;
    }
    cout << t << '\n' ;
}
