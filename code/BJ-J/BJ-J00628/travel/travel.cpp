#include<iostream>
using namespace std;
int c1,s1,c2,s2;
char ch1,ch2;
bool p1,p2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>ch1>>c2>>s2>>ch2;
    if(ch1>'C')
    {
        p1=1;
    }
    if(ch2>'C')
    {
        p2=1;
    }
    if(c1!=c2)
    {
        cout<<"0000";
    }
    else if(s1!=s2)
    {
        cout<<"1000";
    }
    else if(p1!=p2)
    {
        cout<<"1100";
    }
    else if(p1&&p2)
    {
        cout<<"1111";
    }
    else if(ch1!='B'&&ch2!='B')
    {
        cout<<"1110";
    }
    else
    {
        cout<<"1111";
    }
    return 0;
}
