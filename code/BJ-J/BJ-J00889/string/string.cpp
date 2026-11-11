#include <bits/stdc++.h>
using namespace std ;
int main(){
    freopen("string.in","r",stdin) ;
    freopen("string.out","w",stdout) ;
    long long sum = 0 ;
    int n ;
    cin >> n ;
    string s ;
    long long a ;
    char b ;
    for(int i = 0 ; i < n ; i++){
        cin >> a ;
        cin >> b ;
        for(int j = 0 ; j < a ; j++){
            s += b ;
        }
    }
    long long m = s.size() ;
    for(long long i = 0 ; i < m / 2; i++){
        if(s[i] != s[m - 1 - i]){
            sum++ ;
        }
    }
    cout << sum << endl ;
    fclose(stdin) ;
    fclose(stdout) ;
    return 0 ;
}
