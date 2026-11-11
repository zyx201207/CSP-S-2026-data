#include <bits/stdc++.h>
using namespace std ;
#define int long long
struct node 
{
    int cnt ;
    char c ;
}a[200005] ;

signed main()
{
    freopen("string.in" , "r" , stdin) ;
    freopen("string.out" , "w" , stdout) ;
    ios::sync_with_stdio(0) ;
    cin.tie(0) , cout.tie(0) ;
    int ans = 0 , sum = 0 ;
    int n ;
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i].cnt >> a[i].c ;
        sum += a[i].cnt ;    
    }

    int r = n , cnt_l = 0 , cnt_r = 0 , k = sum / 2;

    for(int i = 1 ; i <= n ; i ++)
    {
        if(cnt_l >= k && cnt_r >= k)
            break ;
        if(cnt_l + a[i].cnt <= k)
            cnt_l += a[i].cnt , a[i].cnt = 0 ;
        if(cnt_l + a[i].cnt > k && cnt_l < k)
        {
            int L = k - cnt_l ;
            cnt_l = k ;
            a[i].cnt -= L ;
        }

        while(cnt_r < k && cnt_r < cnt_l)
        {
            if(a[r].cnt + cnt_r <= k && cnt_r + a[r].cnt <= cnt_l)
            {
                cnt_r += a[r].cnt ;
                if(a[i].c != a[r].c)
                    ans += a[r].cnt ;
                a[r].cnt = 0 ;
                r -- ;
            } 
            else if(cnt_r < cnt_l && cnt_r + a[r].cnt > cnt_l)
            {
                if(a[i].c != a[r].c)
                    ans += cnt_l - cnt_r ;
                int L = cnt_l - cnt_r ;
                cnt_r = cnt_l ;
                a[r].cnt -= L ;
            }
        }
    }
    cout << ans << endl;
    return 0 ;
}