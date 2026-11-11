#include <bits/stdc++.h> //100 pts
using namespace std;
#define int long long
struct node {
    int c, p, s;
} r, x;
string c1, s1, c2, s2;
int stoint (string s) {
    int idx = 1;
    int res = 0;
    for (int i = 1; i >= 0; i--) {
        char c = s[i];
        res += (c - '0') * idx;
        idx *= 10;
    }
    return res;
}
bool a, b, c, d;
signed main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    r.c = stoint(c1);
    x.c = stoint(c2);
    r.p = stoint(s1);
    x.p = stoint(s2);
    r.s = s1[2];
    x.s = s2[2];
    if (r.c == x.c) {
        a = 1;
    }
    if (a && r.p == x.p) {
        b = 1;
    }
    if (a && b) {
        if (r.s < 'D' && x.s < 'D') {
            c = 1;
        }
        else if (r.s >= 'D' && x.s >= 'D') {
            c = 1;
        }
    }
    if (a && b && c) {
        if ((int)abs((int)(r.s - x.s)) == 1ll) {
            d = 1;
        }
        else if (r.s >= 'D' && x.s >= 'D') {
            d = 1;
        }
    }
    cout << (int) a << (int) b << (int) c << (int) d << '\n';
    return 0;
}
//freopen("travel.in", "w", stdin);
//freopen("travel.in", "r", stdout);
/*
踏光向前，终成璀璨

有人说，光指向哪里，路就在哪里
如果前方没有光呢？
那就先向前一步，一起去成为光
去寻找那道蕴含生机的光
去成为那道无所畏惧的光
从一次次的相信，到亿万次的坚信
从一道光，汇聚千万道光
微光成聚，聚成星河

不被边界定义
不为尺寸所限
以思想开路
以行动作答
如果此刻
你也看见了一片璀璨
那是千万道这样的光
正同行在路上！

Make It Possible

祝愿华为能越来越好，一往无前！ 
*/