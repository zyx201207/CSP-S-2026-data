#include <cstdio>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
using namespace std;
int a, b;
int c, d;
char c1, c2;
bool flg[210];
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%d %d%c %d %d%c", &a, &c, &c1, &b, &d, &c2);
    flg['A'] = flg['B'] = flg['C'] = true;
    if (a != b) {
        printf("0000");
        return 0;
    }
    printf("1");
    if (c != d) {
        printf("000");
        return 0;
    }
    printf("1");
    if (flg[c1] != flg[c2]) {
        printf("00");
        return 0;
    }
    printf("1");
    if (c2 - c1 == 1 || c2 - c1 == -1) {
        printf("1");
    }
    else printf("0");
    return 0;
}
