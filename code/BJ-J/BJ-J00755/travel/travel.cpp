#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in");
    freopen("travel.out");
    string a1,a2,b1,b2;
    string a3,b3;
    char c1,c2;
    bool t=true;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<a2.size();i++)
    {
        if(a2[i]<='9'&&a2[i]>='0')
        {
            a3[i]==a2[i];
        }
        if(b2[i]<='9'&&b2[i]>='0')
        {
            b3[i]==b2[i];
        }
        if(a2[i]<='A'&&a2[i]>='F')
        {
            c1==a2[i];
        }
        if(b2[i]<='A'&&b2[i]>='F')
        {
            c2==b2[i];
        }
        cout<<c1<<" "<<c2;
    }
    for(int i=0;i<a2.size();i++)
    {
        if(a3[i]!=b3[i])
        {
            cout<<"000";
            return 0;
        }
        else
        {
            cout<<"1";
            t=true;
        }
    }
    if(c1=='A'||c1=='B'||c1=='C'&&c2=='A'||c2=='B'||c2=='C')
    {
        cout<<"1";
    }
    else if(c1=='D'||c1=='F'&&c2=='D'||c1=='F')
    {
        cout<<"1";
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(c1=='A'&&c2=='B')
    {
        cout<<"1";
        return 0;
    }
    if(c1=='C'&&c2=='B')
    {
        cout<<"1";
        return 0;
    }
    else if(c1=='B'&&c1=='A'||c1=='C')
    {
        cout<<"1";
        return 0;
    }
    else if(c1=='D'&&c1=='F')
    {
        cout<<"1";
        return 0;
    }
    else if(c1=='F'&&c1=='D')
    {
        cout<<"1";
        return 0;
    }
    else
    {
        cout<<"0";
        return 0;
    }
    return 0;
}