#include <bits/stdc++.h>
using namespace std;

string c1, c2, s1, s2;
bool t1=0, t2=0, t3=0, t4=0;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;

    t1 = (c1 == c2);
    t2 = (s1.substr(0, 2) == s2.substr(0, 2));

    if (s1[2] < 'D' && s2[2] < 'D') t3 = 1;
    if (s1[2] > 'C' && s2[2] > 'C') t3 = 1;

    if (abs(s1[2] - s2[2]) == 1) t4 = 1;

    cout << (t1);
    cout << (t1 && t2);
    cout << (t1 && t2 && t3);
    cout << (t1 && t2 && t3 && t4);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
