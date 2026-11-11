#include<bits/stdc++.h>
using namespace std;

int main(){
    preopen("travel.in","r",stdin);
    preopen("travel.out","w",stdout);
    int a, b, c, d, f, n, m;
    int c1, s1, c2, s2, x, y;
    cin >> c1, s1, c2, s2;
    if(c1==c2){
        cout << "1";
    }else{
        cout << "0";
    }
    if(c1==c2 && x==y){
        cout << "1";
    }else{
        cout << "0";
    }
    if(c1==c2 && x==y && n==m){
        cout << "1";
    }else{
        cout << "0";
    }
    if(s1+-1==s2 && s2+-1==s1){
        cout << "1";
    }else{
        cout << "0";
    }

    return 0;
}
