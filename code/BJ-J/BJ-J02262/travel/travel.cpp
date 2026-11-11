#include<bits/stdc++.h>

using namespace std;

string cr, sr, cx, sx, ans = "0000";

int main() {

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> cr >> sr >> cx >> sx;
    //cout << cr <<" " << sr << " " << cx << " " << sx;

    if (cr == cx) {
        ans[0] = '1';
    }
    else {
        cout << ans;
        return 0;
    }

    char a = sr[0], b = sx[0];
    char c = sr[1], d = sx[1];
    if (a == b && c == d) {
        ans[1] = '1';
       // cout << ans;
    }
    else {
        cout << ans;
        return 0;
    }
    char e = sr[2], f = sx[2];
    if (e <= 'C' && f <= 'C') {
        ans[2] = '1';
        if (f == e + 1 || f == e - 1) {
            ans[3] = '1';
        }
        else {
            ans[3] = '0';
        }
    }
    else if (e > 'C' && f > 'C') {
        ans[2] = '1';
        ans[3] = '1';
    }
    else {
        ans[2] = '0';
        ans[3] = '0';
    }

    cout << ans;
    return 0;
}
