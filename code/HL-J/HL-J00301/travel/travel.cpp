#include <bits/stdc++.h>
using namespace std;
char s1[10],s2[10],s3[10],s4[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s %s %s %s",s1,s2,s3,s4);
    if (s1[0] == s3[0] && s1[1] == s3[1])
        printf("1");
    else
        printf("0");

    if (s2[0] == s4[0] && s2[1] == s4[1])
        printf("1");
    else
        printf("0");

    if (s1[0] == s3[0] && s1[1] == s3[1] && s2[0] == s4[0] && s2[1] == s4[1] &&
    (('A' <= s2[2] <= 'C' && 'A' <= s4[2] <= 'C')
    || ((s2[2] == 'D' && s4[2] == 'F')
    || (s2[2] == 'F' && s4[2] == 'D'))))
        printf("1");
    else
        printf("0");

    if (s1[0] == s3[0] && s1[1] == s3[1] && s2[0] == s4[0] && s2[1] == s4[1] &&
    ((s2[2] + 1 == s4[2] && s2[2] != 'C')
    || (s2[2] - 1 == s4[2] && s2[2] != 'D')))
        printf("1");
    else
        printf("0");
    return 0;
}
