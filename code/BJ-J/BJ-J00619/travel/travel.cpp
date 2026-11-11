#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string a1,b1;
    cin>>a>>a1>>b>>b1;
    if(a==b)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    int tempa=0,tempb=0;
    tempa=(a1[0]-'0')*10+(a1[1]-'0');
    tempb=(b1[0]-'0')*10+(b1[1]-'0');
    if(tempa==tempb)
    {
        cout<<"1";
        char ta=a1[2],tb=b1[2];
        if((ta=='A'&&tb=='B')||(ta=='B'&&tb=='A'))
        {
            cout<<"11";
        }
        else if((ta=='A'&&tb=='C')||(ta=='C'&&tb=='A'))
        {
            cout<<"10";
        }
        else if((ta=='C'&&tb=='B')||(ta=='B'&&tb=='C'))
        {
            cout<<"11";
        }
        else if((ta=='D'&&tb=='F')||(ta=='F'&&tb=='D'))
        {
            cout<<"11";
        }
        else
        {
            cout<<"00";
        }
    }
    else
    {
        cout<<"000";
    }
    return 0;
}
