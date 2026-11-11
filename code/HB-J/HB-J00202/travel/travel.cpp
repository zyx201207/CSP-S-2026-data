#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    char s1[5],s2[5];
    bool nx4 = false,ok4 = false;
    scanf("%d %s %d %s",&c1,s1,&c2,s2);
    if(c1 == c2)
    {
        printf("1");
        if(s1[0] == s2[0] && s1[1] == s2[1])
        {
            printf("1");
            if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'))
            {
                printf("1");
                nx4 = true;
            }
            else if((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))
            {
                printf("1");
                nx4 = true;
            }
            else
                printf("0");
        }
        else
            printf("00");
    }
    else
        printf("000");
    if(nx4)
    {
        if(s1[2] == 'A' || s1[2] == 'C')
        {
            if(s2[2] == 'B')
                ok4 = true;
        }
        else if(s1[2] == 'B')
        {
            if(s2[2] == 'A' || s2[2] == 'C')
                ok4 = true;
        }
        else if(s1[2] == 'D' && s2[2] == 'F')
            ok4 = true;
        else if(s1[2] == 'F' && s2[2] == 'D')
            ok4 = true;
    }
    printf("%d",(ok4 ? 1 : 0));
    return 0;
}
