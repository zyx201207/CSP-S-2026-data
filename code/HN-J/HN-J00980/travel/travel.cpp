#include<bits/stdc++.h>

using namespace std;

string x1, x2, s1, s2;
int w1 = 0, w2 = 0, w3 = 0, w4 = 0;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> x1 >> s1 >> x2 >> s2;
    if(x1 == x2){
        w1 = 1;
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            w2 = 1;
            if((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')){
                w3 = w4 = 1;
            } else if((s1[2] == 'A' && (s2[2] == 'B' || s2[2] == 'C')) || (s1[2] == 'B' && (s2[2] == 'A' || s2[2] == 'C')) || (s1[2] == 'C' && (s2[2] == 'B' || s2[2] == 'A'))){
                w3 = 1;
                if(s1[2] == 'B' || s2[2] == 'B'){
                    w4 = 1;
                }
            }
        }
    }
    cout << w1 << w2 << w3 << w4;
    return 0;
}
