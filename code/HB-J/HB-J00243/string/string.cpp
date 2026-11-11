#include<bits/stdc++.h>
using namespace std ;
int main(){
    //freopen("string6.in",'r',stdin);
    //freopen("travel.in",'w',stdout);
    string s;
    long long n ;
    long long a ;
    char b;
    cin >> n;
    for(int i = 1 ; i <=n;i++){
        cin >> a;
        cin >> b;
        for(int i = 1 ; i <= a ; i++){
            s[i] = b ;
        }
    }
    cout << s ;
    return 0 ;
}
