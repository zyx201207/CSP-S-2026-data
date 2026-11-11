/*
if (same car, same line, same side and near)
*/

#include <bits/stdc++.h>

using namespace std;

string c1, s1, c2, s2;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 != c2) cout << "0000"; //not same car

    else{
        if(s1[0] != s2[0] || s1[1] != s2[1]) cout << "1000"; //not same line

        else{
            if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
                if(s2[2] == 'D' || s2[2] == 'F') cout << "1100"; //not same side
                else{
                    if(s1[2] == 'A' && s2[2] == 'B') cout << "1111"; //near
                    else if(s1[2] == 'B' && s2[2] == 'A') cout << "1111";
                    else if(s1[2] == 'B' && s2[2] == 'C') cout << "1111";
                    else if(s1[2] == 'C' && s2[2] == 'B') cout << "1111";
                    else cout << "1110"; //not near
                }
            }

            else{
                if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') cout << "1100"; //not same side
                else{
                    if(s1[2] == 'D' && s2[2] == 'F') cout << "1111"; //near
                    else if(s1[2] == 'F' && s2[2] == 'D') cout << "1111";
                    else cout << "1110"; //not near
                }
            }
        }
    }

    return 0;
}
