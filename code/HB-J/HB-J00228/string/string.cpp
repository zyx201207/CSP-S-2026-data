#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int n, temp, cutl, cnt;
char c;
string s;
int main(){
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    while (n --){
        cin >> temp >> c;
        while (temp --) s += c;
    }
    if (s.size() == 1){
        cout << 0;
        return 0;
    }
    cutl = (s.size() - 2) / 2;
    for (int i = 0, it = s.size() - 1; i <= cutl; i ++, it --){
        if (s[i] != s[it]) cnt ++;
    }
    cout << cnt;
    return 0;
}
