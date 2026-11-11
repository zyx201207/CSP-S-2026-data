#include <bits/stdc++.h>
using namespace std;
bool check(string s1 , string s2){
    if ('A' <= s1[s1.size() - 1] && s1[s1.size() - 1] <= 'C' && 'A' <= s2[s2.size() - 1] && s2[s2.size() - 1] <= 'C' ) return 1;
    if ('D' <= s1[s1.size() - 1] && s1[s1.size() - 1] <= 'F' && 'D' <= s2[s2.size() - 1] && s2[s2.size() - 1] <= 'F' ) return 1;
    return 0;
}
bool check2(string s1 , string s2){
    if (abs(s1[2] - s2[2]) == 1 || (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'F')) return 1;
    return 0;
}
int main(){
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    string a , b , c , d;
    cin >> a >> b >> c >> d;
    int p1 = 0 , p2 = 0;
    for (int i = 0; i < b.size(); i++){
        if ('0' <= b[i] && b[i] <= '9') p1 = p1 * 10 + b[i] - '0';
    }
    for (int i = 0; i < d.size(); i++)
        if ('0' <= d[i] && d[i] <= '9') p2 = p2 * 10 + d[i] - '0';
    if (a == c) cout << 1;
    else cout << 0;
    if (a == c && p1 == p2) cout << 1;
    else cout << 0;
    if (a == c && p1 == p2 && check(b , d)) cout << 1;
    else cout << 0;
    if (a == c && p1 == p2 && check(b , d) && check2(b , d)) cout << 1;
    else cout << 0;
    return 0;
}
