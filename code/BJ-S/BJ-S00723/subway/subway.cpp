#include <bits/stdc++.h>
using namespace std ;
#define int long long
int w[500010] , k[500010] ;
bool vis[500010] ;
struct node
{
    int v , p , t; //线路
};
vector<node> edge[500010] ;
vector<int> a[505] , t[505] ;
struct A
{
    int a , b , at , bt;
}b[505] ;
int c , n , m , d , q ; 

int BFS(int x , int y , int id)
{
    memset(vis , 0 , sizeof vis) ;
    queue<int> q , p , k , H;
    int ans = 0 ;
    vis[x] = 1 ;
    q.push(x) ;
    p.push(0) ; 
    k.push(0) ; 
    while(q.size())
    {
        int m = q.front() , d = p.front(), l = k.front() ;
        if(m == y) 
        {
            ans = min(ans, d ) ;
            q.pop() ;
            p.pop() ;
            k.pop() ; 
            continue ;
        }
        q.pop() ;
        p.pop() ;
        k.pop() ; 
        for(auto i : edge[m])
        {
            if(!vis[i.v])
            {
                vis[i.v] = 1 ;
                if(l == i.p)
                {
                    q.push(i.v) ;
                    p.push(d) ;
                    k.push(l) ; 
                }
                else
                {
                    q.push(i.v);
                    p.push(d + i.t) ;
                    k.push(i.p) ;
                }
            }
        }
    }
    return ans ; 
}
signed main()
{
    freopen("subway.in" , "r" , stdin) ;
    freopen("subway.out" , "w" , stdout) ;
    cin >> c >> n >> m >> d >> q ;

    bool flag = 0 ; //两个
    for(int i = 1 ; i <= m ; i ++)
        cin >> w[i] ;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> k[i] ; 
        int l , lt ;
        for(int j = 1 ; j <= k[i] ; j ++)
        {
            int A , T ;
            cin >> A >> T ;
            a[i].push_back(A) ; 
            t[i].push_back(T) ;
            if(j == 2) 
                edge[l].push_back({A , i , lt}) ;  
            l = A , lt = T ;
        }
    }
    while(q --)
    {
        int l , r ;
        cin >> l >> r ;
        cout << w[l] + w[r] + BFS(l , r , 0) << endl;
    }
    return 0 ;
}