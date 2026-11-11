#include <bits/stdc++.h>

int c1, c2;
char s1[100], s2[100];

int main(){
    freopen("travel.in", "r", stdin); freopen("travel.out", "w", stdout);
    scanf("%d %s %d %s", &c1, s1, &c2, s2);
    if(c1 != c2){ puts("0000"); }
    else if(s1[0] != s2[0] || s1[1] != s2[1]){ puts("1000"); }
    else if(s1[2] < 'D' && 'C' < s2[2] || 'C' < s1[2] && s2[2] < 'D'){
        puts("1100");
    }else if(s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1) puts("1111");
    else puts("1110");
    return 0;
}
