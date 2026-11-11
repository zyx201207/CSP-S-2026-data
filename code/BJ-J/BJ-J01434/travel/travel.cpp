#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, c2;
    string b, d;
    cin >> c1 >> b >> c2 >> d;
    char d1 = b.back(), d2 = d.back();
    b.pop_back(), d.pop_back();
    int s1 = stoi(b), s2 = stoi(d);
    bool q1 = (c1 == c2);
    bool q2 = q1 && (s1 == s2);
    bool q3 = q2 && ((d1 <= 'C' && d2 <= 'C') || (d1 >= 'D' && d2 >= 'D'));
    bool q4 = q3 && ((d1 == 'D' && d2 == 'F') || (d1 == 'F' && d2 == 'D') || (abs((int)d2 - (int)d1) == 1));
    cout << q1 << q2 << q3 << q4 << "\n";
    return 0;
}
