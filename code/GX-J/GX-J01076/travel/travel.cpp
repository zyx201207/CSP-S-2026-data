#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,an="";
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        an+='1';
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            an+='1';
            if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')) ||
               ((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))
            {
                an+='1';
                if(abs((s1[2]-0-64)-(s2[2]-0-64))==1)
                {
                    an+='1';
                }
                else
                {
                    an+='0';
                }
            }
            else
            {
                an+="00";
            }
        }
        else
        {
            an+="000";
        }
    }
    else
    {
        an+="0000";
    }
    cout<<an;
    return 0;
}
