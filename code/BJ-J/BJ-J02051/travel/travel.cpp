#include<bits/stdc++.h>
using namespace std;

int n, m;
string a, b;
bool flag1, flag2, flag3, flag4;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> n >> a >> m >> b;
    if (n == m) {
        flag1 = 1;
        if (a[0] == b[0] && a[1] == b[1]) {
            flag2 = 1;
            if ((a[2] >= 'A' && a[2] <= 'C') && (b[2] >= 'A' && b[2] <= 'C')) {
                flag3 = 1;
                if (abs(a[2] - b[2]) == 1)
                    flag4 = 1;
            }
            else if ((a[2] == 'D' && b[2] == 'E') || (a[2] == 'E' && b[2] == 'D'))
                flag3 = flag4 = 1;
        }
    }
    printf("%d%d%d%d", flag1, flag2, flag3, flag4);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
