#include<bits/stdc++.h>
using namespace std ;
string s ;
string a  ;
int n ;
int ans ;
int main(){
    freopen("string.in","r",stdin) ;
    freopen("string.out","w",stdout) ;
    cin >> n ;
    cin >> s;
    cin >> a ;
    int lenn = s.size() ;
    int len = a.size() ;
    for(int i = 0 ; i <= len ; i ++ ){
        for(int i = 0 ; i <= lenn ; i ++ ){
            if(a[i] == s[i]){
                ans++ ;
            }
        }
    }
cout << ans ;











}

