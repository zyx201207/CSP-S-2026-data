#include <bits/stdc++.h>
using namespace std;

char c1[5] ,s1[10] ,c2[5] ,s2[10];
int chx1 ,chx2 ,pai1 ,pai2 ,zw1 ,zw2 ,ce1 ,ce2;

int bh (char s[])
{
    int ans = s[1] - '0';
    ans *= 10;
    ans += s[2] - '0';
    return ans;
}

int main ()
{
    freopen ("travel.in" ,"r" ,stdin);
    freopen ("travel.out" ,"w" ,stdout);
    scanf ("%s %s %s %s" ,c1 + 1 ,s1 + 1 ,c2 + 1 ,s2 + 1);
    chx1 = bh(c1); chx2 = bh(c2);
    if (chx1 != chx2) {printf ("0000\n"); return 0;}
    pai1 = bh(s1); pai2 = bh(s2);
    if (pai1 != pai2) {printf ("1000\n"); return 0;}
    zw1 = s1[3] - 'A'; zw2 = s2[3] - 'A';
    ce1 = zw1 < 3 ? 0 : 1; ce2 = zw2 < 3 ? 0 : 1;
    if (ce1 != ce2) {printf ("1100\n"); return 0;}
    bool flag = false;
    if (zw1 - zw2 == 1) flag = true;
    if (zw2 - zw1 == 1) flag = true;
    if (flag) printf ("1111\n");
    else      printf ("1110\n");
    //printf ("\n%d %d" ,zw1 ,zw2);
    return 0;
}
