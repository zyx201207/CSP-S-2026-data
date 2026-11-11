#include<bits/stdc++.h>
using namespace std;
string c_1, s_1;
string c_2, s_2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> c_1 >> s_1 >> c_2 >> s_2;
    if(c_1 != c_2){
        cout << "0000";
        return 0;
    }
    cout << 1;
    int s1 = (s_1[0] - '0') * 10 + (s_1[1] - '0');
    int s2 = (s_2[0] - '0') * 10 + (s_2[1] - '0');
    if(s1 != s2){
        cout << "000";
        return 0;
    }
    cout << 1;
    if(s_1[2] <= 'C' && s_2[2] > 'C' || s_2[2] <= 'C' && s_1[2] > 'C'){
        cout << "00";
        return 0;
    }
    cout << 1;
    if(s_1[2] - s_2[2] == 1 || s_2[2] - s_1[2] == 1) cout << 1;
    else cout << 0;
    return 0;
}
