#include <bits/stdc++.h>
using namespace std;

string str;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long cnt;
        char ch;
        cin >> cnt >> ch;
        while(cnt--) {
            str += ch;
        }
    }

    long long cnt = 0;
    for(int i = 0; i < str.size() / 2; i++) {
        if(str[i] != str[n - i]) {
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
//aabbc
