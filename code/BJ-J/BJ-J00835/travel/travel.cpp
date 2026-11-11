#include <iostream>
#include <string>
using namespace std;

bool flag1 , flag2 , flag3 , flag4;
int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    string c1 , s1 , c2 , s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) flag1 = true;

    string s11 , s22;
    for (int i = 0; i <= 1; i ++) s11 += s1[i];
    for (int i = 0; i <= 1; i ++) s22 += s2[i];
    if (flag1 && s11 == s22) flag2 = true;

    char w1 = s1[2] , w2 = s2[2];
    if ((flag1 && flag2 && 'A' <= w1 && w1 <= 'C' && 'A' <= w2 && w2 <= 'C') || ('D' <= w1 && w1 <= 'F' && 'D' <= w2 && w2 <= 'F')) flag3 = true;

    if (flag1 && flag2 && flag3)
        if ((w1 == 'D' && w2 == 'F') || (w1 == 'A' && w2 == 'B' || w1 == 'B' && w2 == 'C')) flag4 = true;
    cout << flag1 << flag2 << flag3 << flag4;
    return 0;
}
