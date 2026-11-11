#include <bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[7],s2[7];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d %c%c%c",&c1,&s1[1],&s1[2],&s1[3]);
    scanf("%d %c%c%c",&c2,&s2[1],&s2[2],&s2[3]);
    if(c1 != c2)
    {
        printf("0000");
        return 0;
    }
    printf("1");
    if(s1[1] != s2[1] or s1[2] != s2[2])
    {
        printf("000");
        return 0;
    }
    printf("1");
    if(((s1[3] == 'F' or s1[3] == 'D') and (s2[3] == 'A' or s2[3] == 'B' or s2[3] == 'C')) or ((s2[3] == 'F' or s2[3] == 'D') and (s1[3] == 'A' or s1[3] == 'B' or s1[3] == 'C')))
    {
        printf("00");
        return 0;
    }
    printf("1");
    if((s1[3] == 'A' and s2[3] == 'C') or (s1[3] == 'C' and s2[3] == 'A'))
    {
        printf("0");
        return 0;
    }
    printf("1");
    return 0;
}