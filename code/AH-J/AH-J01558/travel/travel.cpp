#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int c1, c2;
int solve(char c){
    if(c == 'D' || c == 'F') return 1;
    else return 0;
}
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2) cout << "0000";
    else if(s1[0] != s2[0] || s1[1] != s2[1]) cout << "1000";
    else if(solve(s1[2]) != solve(s2[2])) cout << "1100";
    else if(!(abs(int(s1[2] - s2[2])) == 1 || s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D')) cout << "1110";
    else cout << "1111";
    return 0;
}
