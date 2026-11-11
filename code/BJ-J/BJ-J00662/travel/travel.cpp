#include<bits/stdc++.h>
using namespace std;

bool flag1,flag2,flag3;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2)
    {
        cout<<"1";
        flag1=true;
    }
    else
    {
        cout<<"0";
        flag1=false;
    }

    if(flag1&&s1[0]==s2[0]&&s1[1]==s2[1])
    {
        cout<<"1";
        flag2=true;
    }
    else
    {
        cout<<"0";
        flag2=false;
    }

    if(flag2&&(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))
    {
        cout<<"1";
        flag3=true;
    }
    else
    {
        cout<<"0";
        flag3=false;
    }

    if(flag3&&(abs(s1[2]-s2[2])==1&&(s1[2]!='C'&&s2[2]!='D')&&(s1[2]!='D'&&s2[2]!='C'))||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
