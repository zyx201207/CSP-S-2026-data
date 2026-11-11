#include <bits/stdc++.h>
using namespace std;

// #define local
#define int long long

void solve() {
    int t1, t2;
    char c1[4], c2[4];

    scanf("%lld %s %lld %s", &t1, c1, &t2, c2);
    int row1 = (c1[0] - '0') * 10 + c1[1] - '0';
    int row2 = (c2[0] - '0') * 10 + c2[1] - '0';

    printf("%d%d", t1 == t2, t1 == t2 && row1 == row2);

    bool same = false;
    if(t1 == t2 && row1 == row2) {
        if((c1[2] == 'A' || c1[2] == 'B' || c1[2] == 'C') && (c2[2] == 'A' || c2[2] == 'B' || c2[2] == 'C')) {
            printf("%d", true);
            same = true;
        } else printf("%d", false);
    } else printf("%d", false);

    if(t1 == t2 &&  row1 == row2 && same) {
        if(
            (c1[2] == 'A' && (c2[2] == 'B')) ||
            (c1[2] == 'B' && (c2[2] == 'A' || c2[2] == 'C')) ||
            (c1[2] == 'C' && (c2[2] == 'B')) ||
            (c1[2] == 'D' && (c2[2] =='F')) ||
            (c1[2] == 'F' && (c2[2] == 'D'))
        ) {
            printf("%d", true);
        } else printf("%d", false);
    } else printf("%d", false);
}

#undef int

int main(
    #ifdef local
	int argc,
	char* argv[]
    #endif
) {

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	solve();
}
