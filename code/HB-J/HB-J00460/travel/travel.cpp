#include <bits/stdc++.h>
using namespace std;
string cr, sr, cx, sx, ans;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> cr >> sr >> cx >> sx;
    if (cr == cx) ans += "1";
    else {
        cout << "0000";
        return 0;
    }

    if (sr[0] == sx[0] && sr[1] == sx[1]) ans += "1";
    else {
        cout << "1000";
        return 0;
    }

    if (sr[2] == 'A' || sr[2] == 'B' || sr[2] == 'C'){
        if (sx[2] == 'A' || sx[2] == 'B' || sx[2] == 'C') ans += "1";
        else {
            cout << "1100";
            return 0;
        }
    }
    else {
        if (sx[2] == 'D' || sx[2] == 'F') ans += "1";
        else {
            cout << "1100";
            return 0;
        }
    }

    if (sr[2] == 'D' || sr[2] == 'F'){
        if (sx[2] == 'D' || sx[2] == 'F') ans += "1";
        else {
            cout << "1110";
            return 0;
        }
    }
    else if (sr[2] == 'A' || sr[2] == 'C') {
        if (sx[2] == 'B') ans += "1";
        else {
            cout << "1110";
            return 0;
        }
    }
    else {
        if (sx[2] == 'A' || sx[2] == 'C') ans += "1";
        else {
            cout << "1110";
            return 0;
        }
    }
    cout << ans;
    return 0;
}
