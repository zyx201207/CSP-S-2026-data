#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("travel.in", "r", stdin);
    //freopen("travel.out", "w", stdout);
    int a, b, c, d;
    string m, n;
    cin >> a >> b >> m;
    cin >> c >> d >> n;
    if(a != c){
        cout << 0000;
        return 0;
    }
    else if(b != d){
        cout << 1000;
        return 0;
    }
    else if(m == "A" || m == "B" || m == "C" && n == "D" || n == "F"){
        cout << 1100;
        return 0;
    }
    else if(n == "A" || n == "B" || n == "C" && m == "D" || m == "F"){
        cout << 1100;
        return 0;
    }
    else if(m == "A" && n == "C"){
        cout << 1110;
        return 0;
    }
    else if(n == "A" && m == "C"){
        cout << 1110;
        return 0;
    }
    else if(m == "D" && n == "F"){
        cout << 1111;
        return 0;
    }
    else if(n == "D" && m == "F"){
        cout << 1111;
        return 0;
    }
    else if(m == "B" && n == "A" || n == "C"){
        cout << 1111;
        return 0;
    }
    else if(n == "B" && m == "A" || m == "C"){
        cout << 1111;
        return 0;
    }
}
