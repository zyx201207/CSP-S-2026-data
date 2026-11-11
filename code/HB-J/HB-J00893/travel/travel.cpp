#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int c1, c2;
string s1, s2;
bool same_a (int a, int b){
    if (a == b){
        return 1;
    }
    return 0;
}
bool same_b (string a, string b){
    if (a[0] == b[0] && a[1] == b[1]){
        return 1;
    }
    return 0;
}
bool same_c (string a, string b){
    string x, y;
    x = a[2], y = b[2];
    if ((x == "A" && (y == "B" || y == "C")) || (x == "B" && (y == "A" || y == "C")) || (x == "C" && (y == "A" || y == "B")) || (x == "D" && y == "F") || (x == "F" && y == "D")){
        return 1;
    }
    return 0;
}
bool same_d (string a, string b){
    string x, y;
    x = a[2], y = b[2];
    if (((x == "A" && y == "B") || (x == "B" && y == "A")) || ((x == "B" && y == "C") || (x == "C" && y == "B")) || ((x == "D" && y == "F") || (x == "F" && y == "D"))){
        return 1;
    }else if (same_c(a, b) && (x == "D" && y == "F") || (x == "F" && y == "D")){
        return 1;
    }
    return 0;
}
int main (){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    cout << same_a(c1, c2) << same_b(s1, s2) << same_c(s1, s2) << same_d(s1, s2);
    return 0;
}
