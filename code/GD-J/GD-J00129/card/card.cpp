#include <bits/stdc++.h>
using namespace std ;
const int maxn = 2 * 1e5 + 10;
int a[maxn] , ans[maxn] ;
int main ( ) {

  freopen("card.in","r",stdin) ;
   freopen("card.out","w",stdout) ;

    ios::sync_with_stdio(0) ;
    cin.tie(0) ;

    int n , m ;
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i++)
        cin >> a[i] ;
    for (int i = 1 ; i <= n ; i++) {

        set <int> tj ;
        stack <int> p ;
        //cout << i << ":" ;
        for (int j = i ; j <= n ; j++) {
//        	///
//        	for (int k = 1 ; k <= m ; k++) 
//        		cout << tj.count(k) << " " ;
//        	cout << "\n" ;
        	
        	
            if (!tj.count(a[j])) {
            	//cout << "s" << i << " " << j << "\n" ;
                p.push(a[j]) ;
                tj.insert(a[j]) ;
            }else {
                while(!p.empty() && p.top() != a[j]) 
                    {tj.erase(tj.find(p.top())); p.pop() ;}
            }
        }

        for (int i = 1 ; i <= m ; i++) {
            if (tj.count(i)) 
                ans[i] ++ ;
        }
    }

        for (int i = 1 ; i < m ; i++) {
                cout << ans[i] << " " ;
        }   
        cout << ans[m] ;
    return 0 ;
}