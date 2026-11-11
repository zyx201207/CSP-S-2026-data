#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[5],s1[5],c2[5],s2[5];
    scanf("%s %s %s %s",&c1,&s1,&c2,&s2);
    bool flag1 = true,flag2 = true;
    for(int i = 0;i <= 1;i++)
    {
        if(c1[i] != c2[i])
        {
            flag1 = false;
        }
        if(s1[i] != s2[i])
        {

            flag2 = false;
        }
    }
    if(flag1)
    {
        printf("1");
    }
    else
    {
        printf("0000");
        return 0;
    }
    if(flag2)
    {
        printf("1");
    }
    else
    {
        printf("000");
        return 0;
    }
    if(s1[2] >= 'D')
    {
        if(s2[2] >= 'D')
        {
            printf("11");
            return 0;
        }
        else
        {
            printf("00");
            return 0;
        }
    }
    else
    {
        if(s2[2] >= 'D')
        {
            printf("00");
            return 0;
        }
        else
        {
            printf("1");
            if(s1[2] == 'A' && s2[2] == 'C')
            {
                printf("0");
                return 0;
            }
            if(s1[2] == 'C' && s2[2] == 'A')
            {
                printf("0");
                return 0;
            }
            printf("1");
        }
    }
    return 0;
}
