#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    char cc1,cc2;
    int f[6] = {1,1,1,0,-1,0};
    scanf("%d%d%c%d%d%c",&c1,&s1,&cc1,&c2,&s2,&cc2);
    printf("%d",(c1 == c2) ? 1 : 0);
    printf("%d",(c1 == c2 && s1 == s2) ? 1 : 0);
    printf("%d",(c1 == c2 && s1 == s2 && f[cc1-'A'] == f[cc2-'A']) ? 1 : 0);
    printf("%d",(c1 == c2 && s1 == s2 && f[cc1-'A'] == f[cc2-'A'] && (abs(cc1 - cc2) == 1 || cc1 + cc2 == 'D'+'F')) ? 1 : 0);
    return 0;
}
