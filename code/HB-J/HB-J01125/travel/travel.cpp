#include<bits/stdc++.h>
using namespace std;
int s1,s2;
string c1,c2;
int main()
{
    travel.in>>s1>>c1>>s2>>c2;
    if(c1!=c2)
        {
        travel.out<<0000;
    }
    else
    {
        if(c1[0]!=c2[0] or c1[1]!=c2[1])
        {
            travel.out<<1000;
        }
        else
        {
            if((((c1[2]=="A" or c1[2]=="B") or c1[2]=="C") and (c2[2]=="D" or c2[2]=="F")) or (((c2[2]=="A" or c2[2]=="B") or c2[2]=="C") and (c1[2]=="D" or c1[2]=="F")))
            {
                travel.out<<1100;
            }
            else
            {
                if((((c1[2]=="A" and c2[2]=="B") or (c1[2]=="B" and c2[2]=="A")) or ((c1[2]=="B" and c2[2]=="C") or (c1[2]=="C" and c2[2]=="B"))) or ((c1[2]=="D" and c2[2]=="F") or (c1[2]=="F" and c2[2]=="D")))
                {
                    travel.out<<1111;
                }
                else
                {
                    travel.out<<1110;
                }
            }
        }
    }
    return 0;
}
