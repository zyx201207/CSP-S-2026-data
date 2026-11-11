#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,ss1="ABC",ss2="DE";
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        if(s1[1]==s2[1])
        {
                if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))
                {
                    if(s1[2]=='B'||s2[2]=='B')
                    {
                        cout<<"1111";
                    }
                    else
                    {
                        cout<<"1110";
                    }
                }
                else if((s1[2]=='D'||s1[2]=='E')&&(s1[2]=='D'||s1[2]=='E'))
                {
                    cout<<"1111";
                }
                else
                {
                    cout<<"1100";
                }
        }
        else
        {
            cout<<"1000";
        }
    }

    else
    {
        cout<<"0000";
    }



    return 0;
}
