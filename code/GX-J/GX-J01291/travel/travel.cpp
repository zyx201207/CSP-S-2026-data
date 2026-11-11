#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out","w",stdout);
    int c1, c2;
    string s1;
    string s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)cout << 1;
    else{
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    if(s1[0] == s2[0] && s1[1] == s1[1])cout << 1;
    else{
        cout << 0 << 0 << 0;
        return 0;
    }
    if(s1[2] >= 'D'&&s2[2] >= 'D')cout << 1;
    else if(s1[2] <= 'C'&&s2[2] <= 'C')cout << 1;
    else {cout << 0 << 0;return 0;}
    if(s1[2] - 1 == s2[2] || s1[2] + 1 == s2[2])cout << 1;
    else {cout << 0;return 0;}
    return 0;
}
