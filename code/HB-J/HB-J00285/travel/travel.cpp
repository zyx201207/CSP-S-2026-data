#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            if((s1[2]=='D'&&s2[2]=='E') ||(s1[2]=='E'&&s2[2]=='D'))
            {
                printf("1111");
            }
            else if((s1[2]=='D'&&s2[2]!='E') ||(s1[2]=='E'&&s2[2]!='D')||(s2[2]=='D'&&s1[2]!='E') ||(s2[2]=='E'&&s1[2]!='D'))
                printf("1100");
            else
            {
                if(s1[2]=='B'||s2[2]=='B')printf("1111");
                else printf("1110");
            }
        }
        else printf("1000");
    }
    else printf("0000");
}
