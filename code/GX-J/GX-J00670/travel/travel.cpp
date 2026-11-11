#include <iostream>
using namespace std;
int maion()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin >> c1,c2,s1,s2;
    string a == s1[0] + s1[1],b == s2[0] + s2[1],a1 = s1[2],a2 = s2[2];
    if(c1 == c2) cout << 1;
    else cout << 0;
    if(a == b) cout << 1;
    else cout << 0;
    if((a1 == "A" && a2 == "B") || (a1 == "B" && a2 == "C") || (a1 == "D" && a2 == "F")) cout << 1;
    else cout << 0;
    if((a1 == "A" && a2 == "B") || (a1 == "B" && a2 == "C") || (a1 == "D" && a2 == "F")) cout << 1;
    else cout << 0;
    return 0;
}
