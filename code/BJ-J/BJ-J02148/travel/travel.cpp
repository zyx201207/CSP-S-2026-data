#include<bits/stdc++.h>
using namespace std;
string c1[20],s1[30],c2[20],s2[30];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=0;i<2;i++)
    {
        cin>>c1[i];
    }
    for(int i=0;i<3;i++)
    {
        cin>>s1[i];
    }
    for(int i=0;i<2;i++)
    {
        cin>>c2[i];
    }
    if(c1[0]==c2[0]&&c1[0]==c2[0])
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    for(int i=0;i<3;i++)
    {
        cin>>s2[i];
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
        cout<<"1";
        if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'||s1[2]=='A'&&s2[2]=='B'||s2[2]=='A'&&s1[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B')
        {
            cout<<"1"<<"1";
            return 0;
        }
        else if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A')
        {
            cout<<"1"<<"0";
        }
    }
    else
    {
        cout<<"0"<<"0";
    }
    return 0;
}
