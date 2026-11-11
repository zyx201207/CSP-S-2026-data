#include <bits/stdc++.h>
using namespace std ;

#define int long long
int a[500005] , ans[300005] , box[300005] ; 
int box2[500005] ;
signed main()
{
    freopen("card.in" , "r" , stdin) ;
    freopen("card.out" , "w" , stdout) ;
    int n , m , sum = 0 ;
    cin >> n >> m ;
    
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i] ;
    
    if(n <= 5000)
    {
        for(int i = 1 ; i <= n ; i ++)
        {
            stack<int>st ;
            memset(box2 , 0 ,sizeof box) ;
            for(int j = i ; j <= n ; j ++)
            {
                box2[a[j]] ++ ;
                if(box2[a[j]] > 1)
                {
                    while(st.size() && st.top() != a[j])
                        if(st.top() != a[j])
                            st.pop() ;
                    box2[a[j]] -- ;
                }
                st.push(a[j]) ;
            }
            while(st.size())
            { 
                cout << st.top() << endl;
                ans[st.top()] ++ ;
                st.pop() ;
            }
        }
        for(int j = 1 ; j <= m ; j ++)
            cout << ans[j] << " " ; 
    }
    else
    {
        for(int i = 1 ; i <= n ; i ++)
            ans[a[i]] ++ ;
    
        for(int i = 1 ; i <= m ; i ++)
            sum += ans[i] ;
        for(int i = n ; i >= 1 ; i --)
        {
            if(box[a[i]])
                continue ;
            if(box[a[i]] == 0)
            {
                sum -= ans[a[i]] ;
                ans[a[i]] += sum ;
                box[a[i]] = 1 ;            
            }
        }
        // cout<<endl;
        for(int i = 1 ; i <= m ; i ++)
            cout << ans[i] << " " ;
    }

    return 0 ;
}