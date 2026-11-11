#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string R_place, R_seat, X_place, X_seat;
    cin >> R_place >> R_seat >> X_place >> X_seat;
    string ans = "";
    if(R_place == X_place) {
        ans += '1';
        if(R_seat[0] == X_seat[0] && R_seat[1] == X_seat[1]) {
            ans += '1';
            if(((R_seat[2] == 'A' || R_seat[2] == 'B' || R_seat[2] == 'C') && (X_seat[2] == 'A' || X_seat[2] == 'B' || X_seat[2] == 'C')) || ((R_seat[2] == 'D' || R_seat[2] == 'F') && (X_seat[2] == 'D' || X_seat[2] == 'F'))) {
                ans += '1';
                if((R_seat[2] == 'A' && X_seat[2] == 'B') || (R_seat[2] == 'B' && X_seat[2] == 'C') || (R_seat[2] == 'B' && X_seat[2] == 'A') || (R_seat[2] == 'C' && X_seat[2] == 'B') || (R_seat[2] == 'D' && X_seat[2] == 'F') || (R_seat[2] == 'F' && X_seat[2] == 'D')) {
                    ans += '1';
                }
                else {
                    ans = "1110";
                }
            }
            else {
                ans = "1100";
            }
        }
        else {
            ans = "1000";
        }
    }
    else {
        ans = "0000";
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
