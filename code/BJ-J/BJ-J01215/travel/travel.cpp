#include<iostream>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);

    string s1,s2,h1,h2;
    cin>>h1>>s1>>h2>>s2;
    if(h1==h2)cout<<"1";
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])
        cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
        cout<<"1";
    else
    {
        cout<<"00";
        return 0;
    }
    if(s1[2]==s2[2]+1||s1[2]+1==s2[2])
        cout<<"1";
    else{
        cout<<"0";
        return 0;
    }
    freopen("travel.out","w",stdout);
    return 0;
}
