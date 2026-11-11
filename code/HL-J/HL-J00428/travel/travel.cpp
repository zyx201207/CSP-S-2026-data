#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1, c2, s1, s2;
bool flag = false;
bool solve() {
    if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
        if (s2[2] == 'D' || s2[2] == 'F') {
            return false;
        }
        return true;
    }
    if (s1[2] == 'D' || s1[2] == 'F') {
        if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
            return false;
        }else {
            return true;
        }
    }
}
bool solve2() {
    if (s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D') {
        return true;
    }
    int n = s1[2] - 'A' - '0';
    int m = s2[2] - 'A' - '0';
    if (n - m == 1 || m - n == 1) {
        return true;
    }
    return false;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> c1 >> s1 >> c2 >> s2;

    if (c1[0] == c2[0] && c1[1] == c2[1]) {
        cout << 1;
        flag = true;
    }else{
        flag = false;
        cout << 0;
    }

    if (s1[0] == s2[0] && s1[1] == s2[1] && flag == true) {
        cout << 1;
    }else {
        flag = false;
        cout << 0;
    }

    if (solve() && flag == true) {
        cout << 1;
    }else {
        flag = false;
        cout << 0;
    }

    if (flag == true && solve2()) {
        cout << 1;
    }else {
        cout << 0;
    }
    return 0;
}

