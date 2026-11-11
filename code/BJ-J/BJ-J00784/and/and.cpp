#include <bits/stdc++.h>
using namespace std ;
#define int long long
int a[200005] ;
string s[200005] ;
queue<int> q ; 

int ch(int x)
{
    string S = "" ;
    int tmp = a[x] ;
    while(tmp)
    {
        if(tmp % 2 == 0)
            S = "0" + S ;
        else 
            S = "1" + S ;
        tmp /= 2 ;
    }
    s[x] = S ;
    return S.size() ;
}

signed main()
{ 
    freopen("and.in" , "r" , stdin) ;
    freopen("and.out" , "w" , stdout) ;
    ios::sync_with_stdio(0) ;
    cin.tie(0) , cout.tie(0) ;
    int n , m , maxn = 0 ;
    cin >> n >> m ;

    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i] ;

    for(int i = 1 ; i <= n ; i ++)
        maxn = max(maxn , ch(i)) ;

    for(int i = 1 ; i <= n ; i ++)
    {
        q.push(i) ;
        int l = s[i].size() ;
        for(int j = 1 ; j <= maxn - l ; j ++)
            s[i] = "0" + s[i] ;
        // cout << s[i] << endl;
    }

    int sum = n ; // 当前还有多少个备选数字 
    for(int i = 0 ; i < maxn ; i ++)
    {
        int cnt = 0 , l = 0;
        while(l < sum)
        {
            l ++ ;
            int k = q.front() ;
            if(s[k][i] == '1')
                cnt ++ ;
            q.pop() ;
            q.push(k) ;
            if(l == sum)
                break ;
        }
        if(cnt >= m)
        {  
            l = 0 ;
            int n_sum = 0 ;
            while(l < sum)
            {
                l ++ ;
                int k = q.front() ;
                q.pop() ;
                if(s[k][i] == '1')
                { 
                    q.push(k) ;
                    n_sum ++ ; 
                }             
                if(l == sum)
                    break ;        
            }
            sum = n_sum ;
        }
        // int t = 1 , p = q.size();
        // while(t <= p)
        // {
        //     cout << q.front() << " " ;
        //     q.push(q.front()) ;
        //     q.pop() ;
        //     t ++ ;
        // }
        // cout << endl;
        // cout << sum << endl;
    }

    int cnt = 1 , ans = a[q.front()] ;
    q.pop() ;
    while(cnt < m)
    { 
        ans = ans & a[q.front()] ;
        q.pop() ;
        cnt ++ ; 
    }
    cout << ans << endl;
    return 0 ;
}