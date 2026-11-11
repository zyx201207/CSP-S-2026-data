#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

// 左侧座位
bool lseat(char c) {
    return c == 'A' || c == 'B' || c == 'C';
}

// 检查相邻
bool check(char l, char r) {
    if (lseat(l) == 1 && lseat(r) == 1) {
        if (l < r) return r == l + 1;
        else if (r > l) return l == r - 1;
    } else if (lseat(l) == 0 && lseat(r) == 0) return true;
    return false;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    // 车厢
    if (c1 == c2) printf("1");
    else {
        printf("0000");
        return 0;
    }
    // 排
    string row1 = s1.substr(0, 2);
    string row2 = s2.substr(0, 2);
    if (row1 == row2) printf("1");
    else {
        printf("000");
        return 0;
    }
    // 同侧
    char seat1 = s1[2], seat2 = s2[2];
    if (lseat(seat1) == lseat(seat2) && row1 == row2) printf("1");
    else {
        printf("00");
        return 0;
    }
    if (check(seat1, seat2)) printf("1");
    else printf("0");
    return 0;
}

// Trick or Treat!
