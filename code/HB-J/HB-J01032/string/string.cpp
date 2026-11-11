#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n; cin >> n;
    string s;

    for(int i = 0; i < n; i++){
        int t; char c;
        cin >> t >> c;
        for(int i = 0; i < t; i++)s += c;
    }
    cout << s << '\n';

    int i = 0, j = s.size()-1, cnt = 0;

    while(i < j)if(s[i++] != s[j--])cnt++;

    cout << cnt;

    return 0;
}
