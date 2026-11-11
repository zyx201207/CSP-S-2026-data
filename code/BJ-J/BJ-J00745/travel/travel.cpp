#include<bits/stdc++.h>
#define int long long
using namespace std;

string c1,s1,c2,s2;

signed main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >> c1 >> s1 >> c2 >> s2;

    int w1 = s1[2] - 'A' + 1,w2 = s2[2] - 'A' + 1;
    if(w1 == 6) w1 = 5;
    if(w2 == 6) w2 = 5;

    if(c1 == c2) cout << '1';
    else cout << '0';

    if(c1 == c2 && (s1[0] == s2[0] && s1[1] == s2[1]))cout << '1';
    else cout << '0';

    if(c1 == c2 && (s1[0] == s2[0] && s1[1] == s2[1]) && ((w1 <= 3 && w2 <= 3) || (w1 >= 4 && w2 >= 4))) cout << '1';
    else cout << '0';

    if(c1 == c2 && (s1[0] == s2[0] && s1[1] == s2[1]) && ((w1 <= 3 && w2 <= 3) || (w1 >= 4 && w2 >= 4)) && (w1 - w2 == 1 || w2 - w1 == 1)) cout << '1';
    else cout << '0';

    return 0;
}
