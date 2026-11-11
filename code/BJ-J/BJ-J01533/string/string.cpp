/*
change at least how many letters can turn S into a string that reverse(s) = s
68pts
*/

#include <bits/stdc++.h>

using namespace std;

long long n;
long long a;
long long cnt;
char c;
string s;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> c;
        for(int j = 1; j <= a; j++) s += c;
    }

    int l = s.size() / 2;

    for(int i = 0; i < l; i++){
        if(s[i] != s[s.size() - 1 - i]) cnt++;
    }

    cout << cnt;

    return 0;
}
