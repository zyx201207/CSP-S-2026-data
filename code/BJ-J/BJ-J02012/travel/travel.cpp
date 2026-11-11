#include <iostream>
using namespace std;

int l[]{1, 1, 1, 0, 0};
int r[]{0, 0, 0, 1, 1};

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int seat1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    int seat2 = (s2[0] - '0') * 10 + (s2[1] - '0');
    int cc1 = s1[2] - 'A', cc2 = s2[2] - 'A';
    //1
    if (c1 == c2) cout << 1;
    else cout << 0;
    //2
    if (c1 == c2 && seat1 == seat2) cout << 1;
    else cout << 0;
    //3
    if (c1 == c2 && seat1 == seat2 && ((l[cc1] == l[cc2]) || (r[cc1] == r[cc2]))) cout << 1;
    else cout << 0;
    //4
    if (c1 == c2 && seat1 == seat2 && ((l[cc1] == l[cc2]) || (r[cc1] == r[cc2])) && abs(cc1 - cc2) == 1 && ((cc1 != 2 && cc2 != 3) || (cc1 != 3 && cc2 != 2))) cout << 1;
    else cout << 0;
    return 0;
}
