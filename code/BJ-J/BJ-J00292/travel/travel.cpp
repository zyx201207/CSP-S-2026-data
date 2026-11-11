#include<bits/stdc++.h>
using namespace std;
char s[15];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=0;i<13;i++)
    {
        if(i==2||i==6||i==9)
        {
            s[i]=' ';
            continue;
        }
        cin>>s[i];
    }
    if(s[0]==s[7]&&s[1]==s[8])
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s[3]==s[10]&&s[4]==s[11])
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(s[5]=='A'&&s[12]=='B'||s[5]=='A'&&s[12]=='C'||s[5]=='B'&&s[12]=='C'||s[5]=='D'&&s[12]=='F'||s[5]=='B'&&s[12]=='A'||s[5]=='C'&&s[12]=='A'||s[5]=='C'&&s[12]=='B'||s[5]=='F'&&s[12]=='D')
    {
        cout<<"1";
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(s[5]=='A'&&s[12]=='C'||s[5]=='C'&&s[12]=='A')
    {
        cout<<"0";
    }
    else
    {
        cout<<"1";
    }
    return 0;
}
