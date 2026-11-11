#include <bits/stdc++.h>

using namespace std;

string c1,s1,c2,s2;
int if1,if2,if3,if4;

int ifl(string s1,string s2)
{
    if(s1[2]<='C'&&s1[2]>='A')
    {
        if((s1[2]-1==s2[2])||(s2[2]-1==s1[2]))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 1;
    }
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    //cout<<c1<<c2<<s1<<s2;
    if(c1==c2)
    {
        if1=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            if2=1;
            if((s1[2]<='C'&&s1[2]>='A')==(s2[2]<='C'&&s2[2]>='A'))
            {
                if3=1;
                if4=ifl(s1,s2);
            }
            else
            {
                if3=0;
                if4=0;
            }
        }
        else
        {
            if2=0;
            if3=0;
            if4=0;
        }
    }
    else
    {
        if1=0;
        if2=0;
        if3=0;
        if4=0;
    }
    cout<<if1<<if2<<if3<<if4<<endl;
    return 0;
}
