#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
bool b = true;
string s;
void chk(string s) {
    long long l = s.size();
    for(long long i = 0; i < l / 2; i++) {
        if(s[l - i - 1] != s[i]) {
            cnt++;
            b = false;
        }
    }
}
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    while(n--) {
        int a;
        char c;
        cin >> a >> c;
        while(a--) s += c;
    }
    chk(s);
    if(b) cout << 0 << endl;
    else {
        cout << cnt << endl;
    }
    return 0;
}