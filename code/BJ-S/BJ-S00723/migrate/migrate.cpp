#include <bits/stdc++.h>
using namespace std ;
#define int long long
int x[2000006] ;
int n , d , b ;

bool bfs(int st , int y)
{
    queue<int> q , q1 ;
    q.push(st) ;
    q1.push(1) ;
    int minn = 1e18 , cnt = 0 ;
    while(q.size())
    {
        int v = q.front() , w = q1.front();
        q.pop() , q1.pop() ;
        if(v == y)
        {
            if(minn == 1e9)
                minn = w , cnt = 1 ;
            else 
                if(minn == w)
                    cnt ++ ;
        }
        for(int i = v + 1 ; i <= n ; i ++)
        {
            if(x[i] - x[v] <= d)
            {
                q.push(i) ;
                q1.push(w + 1) ;
            }
        }
    }
    return cnt == 2 ;
}

signed main()
{
    freopen("migrate.in" , "r" , stdin) ;
    freopen("migrate.out" , "w" , stdout) ;
    int c , t ;
    cin >> c >> t ;
    while(t --)
    {
        cin >> n >> d ;
        for(int i = 1 ; i <= n ; i ++)
            cin >> x[i] ;
        b = x[2] - x[1] ;
        bool f1 = 0 ;
        for(int i = 3 ; i <= n ; i ++)
            if(x[i] - x[i - 1] != b)
                f1 = 1;
        if(n <= 5000)
        {
            int ans = 0 ;
            for(int i = 1 ; i <= n ; i ++)
            {
                for(int j = i + 1 ; j <= n ; j ++)
                {
                    if(bfs(i , j))
                        ans ++ ;
                } 
            }
            cout << ans << endl;
        }
        else if(!f1)
        {
            if(d <= b)
                cout << 0 << endl ;
            else
            {
                int ans = 0 ;
                for(int i = 1 ; i < n ; i ++)
                    if(b < d * i && 2 * b > d * i)
                        ans = ans + (n - i + 1) ;

                cout << ans << endl ;
            }
        } 
        else
        { 
            int ans = 0 ;
            for(int i = 1 ; i < n ; i ++)
                if(b < d * i && 2 * b > d * i)
                    ans = ans + (n - i + 1) ;

            cout << ans << endl ;
        }
    }
    return 0 ;
}