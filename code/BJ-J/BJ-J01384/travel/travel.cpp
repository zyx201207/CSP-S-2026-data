#include<bits/stdc++.h>
using namespace std;
bool a(char a,char b)
{
    if(a=='A'&&b=='B')return 1;
    if(a=='B'&&b=='C')return 1;
    if(a=='D'&&b=='F')return 1;
    return 0;
}
int main()
{

    //((s2[2]=='A'||s2[2]=='B'||s2[2]=='B')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='B'))
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)
    {
        if(s2[0]==s4[0]&&s2[1]==s4[1])
        {
            if(((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C'))||((s2[2]=='D'||s2[2]=='F')&&(s4[2]=='D'||s4[2]=='F')))
            {

                if(a(min(s2[2],s4[2]),max(s2[2],s4[2])))
                {
                    cout<<"1111";
                }
                else
                {
                    cout<<"1110";
                }
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
