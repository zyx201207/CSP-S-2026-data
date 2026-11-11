#include <bits/stdc++.h>
using namespace std ;
int a[500010] ;
int h[300010] ;
bool b[300010] ;
stack<int> s ;
int main(){
    freopen("card.in","r",stdin) ;
    freopen("card.out","w",stdout) ;
    int n,m,x ;
    cin >> n >> m ;
    for (int i=1 ; i<=n ; i++){
        cin >> a[i] ;
    }
    for (int i=1 ; i<=n ; i++){
        memset(b,0,sizeof(b)) ;
        for (int j=i ; j<=n ; j++){
            if (b[a[j]]){
                while(!s.empty()){
                    if (s.top()!=a[j]){
                        b[s.top()]=false ;
                        s.pop() ;

                    }
                    else {
                        break ;
                    }
                }
            }
            else {
                s.push(a[j]) ;
                b[a[j]]=true ;
            }
        }
        while(!s.empty()){
            x=s.top() ;
            h[s.top()]++ ;
            s.pop() ;
        }
    }
    for (int i=1 ; i<=m ; i++){
        cout << h[i] << " " ;
    }
    return 0 ;
}
