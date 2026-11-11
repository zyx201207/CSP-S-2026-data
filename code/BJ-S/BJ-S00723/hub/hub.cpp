#include <bits/stdc++.h>
using namespace std ;
#define int long long
vector<int> edge[2000010] ;
int n , k , f[2000010];
int color[2000010] ;
struct node 
{
    int depth , id ;
} a[2000010] ;

void printt()
{
    for(int i = 1 ; i <= n ; i ++)
        cout << color[i] << " " ;
}
void dep(int x , int depth , int pre)
{
    f[x] = pre ;
    a[x].depth = depth ;
    a[x].id = x ;
    for(auto i : edge[x])
        if(i != pre)
            dep(i , depth + 1 , x) ;
}

int solve(int k)
{
    int cnt = 0 ;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(color[i])
            continue ;
        int x = a[i].id , c = 0 ;
        bool fl = 0 ;
        while(c < k)
        {
            if(color[x] == 1)
            {
                fl = 1 ;
                break ;
            }
            x = f[x] ;
            c++ ;
        }
        if(fl)
            continue ;
        else
        {
            cnt ++ ;
            color[x] = 1 ;
            int x = a[i].id , c = 0 ;
            while(c < k)
            {
                if(!color[x])
                    color[x] = 2 ;
                x = f[x] ;
                c ++ ;
            }
        }
        // printt() ;
        // cout << endl;
    }
    return cnt ;
}

bool check(int x)
{
    memset(color , 0 , sizeof color) ;
    return solve(x) <= k ;
}

bool cmp(node x , node y)
{
    return x.depth > y.depth ;
}


signed main()
{
    freopen("hub.in" , "r" , stdin) ;
    freopen("hub.out" , "w" , stdout) ;
    ios::sync_with_stdio(0) ; 
    cin.tie(0) , cout.tie(0) ;
    int c , t ;
    cin >> c >> t ;

    while(t --)
    {
        cin >> n >> k ;
        memset(f , 0 , sizeof f) ;
        memset(a , 0 , sizeof a) ;
        memset(color , 0 ,sizeof color) ;
        for(int i = 1 ; i <= n ; i ++)
            edge[i].clear() ;
        for(int i = 1 ; i < n ; i ++)
        {
            int u , v ;
            cin >> u >> v ;
            edge[u].push_back(v) ;
            edge[v].push_back(u) ; 
        }
        
        dep(1 , 1 , 0) ; //以1为根，求深度

        // cout << "此时树的基础数据如下:" << endl;
        // for(int i = 1 ; i <= n ; i ++)
        //     cout << a[i].depth << " " << f[i] << " " << i << endl;

        sort(a + 1 , a + n + 1 , cmp) ;

        f[1] = 0 ;
        int l = 1 , r = n - 1 , ans = 0; 
        while(l <= r) //最大值最小考虑二分答案
        {
            int mid = l + r >> 1 ;
            if(check(mid))
                ans = mid , r = mid - 1 ;
            else
                l = mid + 1 ;
            // cout << "当mid为" << mid << "时，染色为：" << endl;
            // printt() ;
            // cout << endl;
        } 
        cout << ans << endl ;
    }
    return 0 ;
}