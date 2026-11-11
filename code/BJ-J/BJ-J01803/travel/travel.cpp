#include <bits/stdc++.h>
using namespace std;
bool flag = true, flag1 = true, flag2 = false, flag3 = false;
string c, s, c1, s1;
int main (){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c >> s >> c1 >> s1;
    for (int i = 0;i < c.size();i++)
        if (!(c[i] == c1[i]))
            flag = false;
    if (flag) cout << "1";
    else cout << "0";
    for (int i = 0;i <= s.size();i++){
        if ((s[i] >= '0' && s[i] <= '9') && (s1[i] >= '0' && s1[i] <= '9'))
            if (!(s[i] == s1[i]))
                flag1 = false;
    }
    if (flag1) cout << "1";
    else cout << "0";
    if (s[2] < 'D' && s1[2] < 'D')
        flag2 = true;
    else if (s[2] >= 'D' && s1[2] >= 'D')
        flag2 = true;
    if (flag2) cout << "1";
    else cout << "0";
    if (s[2] == s1[2]-1 || s[2] == s1[2]+1){
        if (s[2] != 'C' && s1[2] != 'D') flag3 = true;
    }
    if (flag3) cout << "1";
    else cout << "0";
    return 0;
}
