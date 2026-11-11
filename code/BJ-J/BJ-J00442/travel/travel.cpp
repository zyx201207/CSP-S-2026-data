#include<bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    int l1, l2, seat1, seat2;
    l1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    l2 = (s2[0] - '0') * 10 + (s2[1] - '0');
    if(s1[2] == 'D') seat1 = 5;
    else seat1 = (s1[2] - 'A' + 1);
    if(s2[2] == 'D') seat2 = 5;
    else seat2 = (s2[2] - 'A' + 1);
    if(c1 == c2){
        cout << '1';
        if(l1 == l2){
            cout << '1';
            if((seat1 <= 3 && seat2 <= 3) || (seat1 >= 5 && seat2 >= 5)){
                cout << '1';
                if(abs(seat1 - seat2) == 1) cout << '1';
                else cout <<'0';
            }
            else cout << "00";
        }
        else cout <<"000";
    }
    else cout << "0000";
    return 0;
}
