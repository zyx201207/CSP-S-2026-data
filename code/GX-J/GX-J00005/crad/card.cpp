#include <bits/stdc++.h>
using namespace std ;

int main()
{
    freopen("card.in","r",stdin) ;
    freopen("card.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    int n , m ;
    cin >> n >> m ;
    vector<int> a(n+1) ;
    vector<int> cnt(m+1,0) ;
    map<int,bool> flag ;
    stack<int> s ;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
        flag[a[i]] = false ;
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = i ; j <= n ; j++) {
            if (flag[a[j]]) {
                while (s.top() != a[j]) {
                    flag[s.top()] = false ;
                    s.pop() ;
                }
                s.pop() ;
            }
            flag[a[j]] = true ;
            s.push(a[j]) ;
        }
        while (!s.empty()) {
            cnt[s.top()]++ ;
            flag[s.top()] = false ;
            s.pop() ;
        }
    }
    for (int i = 1 ; i <= m ; i++) {
        cout << cnt[i] << " " ;
    }
    return 0 ;
}
