#include <bits/stdc++.h>
using namespace std;

int main(){
    int c1, c2, se1, se2;
    char so1, so2;
    string s1, s2;
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 == c2) cout << "1";
    else cout << "0";

    se1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    se2 = (s2[0] - '0') * 10 + (s2[1] - '0');
    if(c1 == c2 && se1 == se2) cout << "1";
    else cout << "0";

    so1 = s1[2];
    so2 = s2[2];
    if(c1 == c2 && se1 == se2 && 
        ((so1 != 'D' && so1 != 'F' && so2 != 'D' && so2 != 'F')
         || so1 == 'D' && so2 == 'F' || so1 == 'F' && so2 == 'D'))
          cout << "1";
    else cout << "0";

    if(c1 == c2 && se1 == se2 && 
    (so1 == 'A' && so2 == 'B' || so1 == 'B' && so2 == 'A'
     || so1 == 'B' && so2 == 'C' || so1 == 'C' && so2 == 'B'
     || so1 == 'D' && so2 == 'F' || so1 == 'F' && so2 == 'D')) cout << "1";
    else cout << "0";

    puts("");
    return 0;
}