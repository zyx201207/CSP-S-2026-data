#include<bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool flag=true,n=true;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<=1;i++)
    {
        if(c1[i]!=c2[i])
        {
            n=false;
            break;
        }
    }
    if(n==true)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<=1;i++)
    {
        if(s1[i]!=s2[i])
        {
            flag=false;
            break;
        }
    }
    if(flag==true)
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(s1[2]=='C'&&s2[2]=='D')
    {
        cout<<"00";
        return 0;
    }
    else
    {
        if(s1[2]>='A'&&s1[2]<='C')
        {
            if(s2[2]>='A'&&s2[2]<='C')
            {
                cout<<"1";
            }
            else
            {
                cout<<"0";
            }
        }
        else
        {
            if(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F')
            {
                cout<<"11";
                return 0;
            }
            else
            {
                cout<<"0";
            }
        }
    }
    if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F')
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
