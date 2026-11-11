#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

string c, s, c2, s2;
bool uppos(string s){
    char ch = s[2];
    if(ch == 'D' || ch == 'F') return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c >> s >> c2 >> s2;
    if(c == c2) cout << 1;
    else{
        cout << "0000";
        return 0;
    }
    if(s[0] == s2[0] && s[1] == s2[1]) cout << 1;
    else{
        cout << "000";
        return 0;
    }
    if(uppos(s) == uppos(s2)) cout << 1;
    else{
        cout << "00";
        return 0;
    }
    int num = s[2] - 'A', num2 = s2[2] - 'A';
    if(abs(num - num2) == 1) cout << 1;
    else cout << 0;
    return 0;
}
