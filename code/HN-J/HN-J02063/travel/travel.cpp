#include <bits/stdc++.h>
#define ll long long
#define AC return 0
#define vei vector <int>
#define vel vector <ll>
#define pb push_back
#define db double

using namespace std;

string c[3] , s[3];

bool check(){
    int f1 , f2;
    if (s[1][2] >= 'A' && s[1][2] <= 'C'){
        f1 = 1;
    } else {
        f1 = 2;
    }
    if (s[2][2] >= 'A' && s[2][2] <= 'C'){
        f2 = 1;
    } else {
        f2 = 2;
    }
    return f1 == f2;
}

bool f(){
    if (s[2][2] == 'F' && s[1][2] == 'D'){
        return 1;
    } else if (s[2][2] == 'B' && s[1][2] == 'A'){
        return 1;
    } else if (s[2][2] == 'B' && s[1][2] == 'C'){
        return 1;
    }
    return 0;
}

int main(){
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    for (int i = 1;i <= 2;i++){
        cin >> c[i] >> s[i];
    }
    if (c[1] != c[2]){
        cout << "0000";
        AC;
    } else {
        cout << '1';
    }
    if (s[1][0] == s[2][0] && s[1][1] == s[2][1]){
        cout << 1;
    } else {
        cout << "000";
        AC;
    }
    if (check()){
        cout << 1;
    } else {
        cout << "00";
        AC;
    }
    if (f()){
        cout << 1;
    } else {
        cout << 0;
    }
    AC;
}
/**

*/
