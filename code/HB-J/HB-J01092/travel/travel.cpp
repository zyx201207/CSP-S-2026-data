#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c[10],s[10];
    cin >> c[1] >> s[1] >> c[2] >> s[2];

    int n = 0,m = 0,a = 0,b = 0;
    if(c[1] == c[2]){
        n = 1;
        cout << n;
    }else{cout << "0";}

    if(n == 1){
        if(s[1]-"A" == s[2]-"A"){
            m = 1;
            cout << m;
        }else{cout << "0";}
    }else{cout << "0";}

    if(m == 1){
        if(s[1]-){
            a = 1;
            cout << a;
        }else{cout << "0";}
    }else{cout << "0";}

    if(a == 1){
        if(s[2]-s[1]==1){
            b = 1;
            cout << b;
        }else{cout << "0";}
    }else{cout << "0";}

    return 0;
}
