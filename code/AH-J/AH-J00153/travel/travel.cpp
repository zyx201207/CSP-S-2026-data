# include <bits/stdc++.h>
using namespace std;
int c1 , s1 , c2 , s2;
char sc1 , sc2;
int main () {
    freopen ("travel.in" , "r" , stdin);
    freopen ("travel.out" , "w" , stdout);
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    cin >> c1 >> s1 >> sc1 >> c2 >> s2 >> sc2;
    if (c1 != c2) {
        cout << "0000";
        return 0;
    }
    cout << "1";
    if (s1 != s2) {
        cout << "000";
        return 0;
    }
    cout << "1";
    if ((sc1 <= 'C' && sc2 >= 'D') || (sc1 >= 'D' && sc2 <= 'C')) {
        cout << "00";
        return 0;
    }
    cout << "1";
    if ((sc1 == 'A' && sc2 == 'C') || (sc1 == 'C' && sc2 == 'A')) {
        cout << "0";
        return 0;
    }
    cout << "1";
    return 0;
}
