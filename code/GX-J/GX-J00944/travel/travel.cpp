#include <iostream>
#include <fstream>

using namespace std;

bool a, b, c, d;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    a = (c1 == c2);
    b = (s1.substr(0, 2) == s2.substr(0, 2));
    c = ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F'));
    if (s1[2] > s2[2])
        swap(s1, s2);
    d = ((s2[2] - s1[2] == 1 && s1[2] != 'C') || (s1[2] == 'D' && s2[2] == 'F'));

    cout << a << (a & b) << (a & b & c) << (a & b & c & d);
    return 0;
}
