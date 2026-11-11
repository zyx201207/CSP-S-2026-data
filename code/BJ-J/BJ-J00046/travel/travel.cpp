int get(string s) {
    return s[0] * 10 + s[1];
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool f1 = get(c1) == get(c2);
    cout << f1;
    bool f2 = f1 && get(s1) == get(s2);
    cout << f2;
    bool f3 = f2 & (s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C');
    cout << f3;
    bool f4 = f3 & (abs(s1[2] - s2[2]) == 1);
    cout << f4;
    return 0;
}
//g++ -o o.exe travel.cpp
/*
*/
