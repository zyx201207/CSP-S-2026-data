#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        cout << "0000" << '\n';
        return 0;
    }
    cout << 1;
    int a1 = (s1[0] - '0') * 10 + s1[1] - '0';
    int a2 = (s2[0] - '0') * 10 + s2[1] - '0';
    char ch1 = s1[2];
    char ch2 = s2[2];
    if(a1 != a2){
        cout << "000" << '\n';
        return 0;
    }
    cout << 1;
    if(ch1 <= 'C' && ch2 <= 'C') cout << 1;
    else if(ch1 >= 'D' && ch2 >= 'D') cout << 1;
    else {
        cout << "00" << '\n';
        return 0;
    }
    if(abs(ch1 - ch2) == 1) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}
