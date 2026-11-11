#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    int m = ((int)s1[0]-48)*10+((int)s1[1]-48);
    int n = ((int)s2[0]-48)*10+((int)s2[1]-48);
    if(m==n)
    {
        cout<<"1";

    }
    else{
        cout<<"000";
        return 0;
    }
    char a = s1[2];
    char b = s2[2];
    if((a=='A'&&b=='B')||(b=='A'&&a=='B')||(a=='A'&&b=='C')||(b=='A'&&a=='C')
       ||(a=='B'&&b=='C')||(b=='B'&&a=='C')||(a=='D'&&b=='F')||(b=='D'&&a=='F'))
    {
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if((a=='A'&&b=='B')||(b=='A'&&a=='B')||(a=='B'&&b=='C')||(b=='B'&&a=='C')||(a=='D'&&b=='F')||(b=='D'&&a=='F'))

    {
           cout<<"1";
    }
    else{
        cout<<"0";
    }



    return 0;
}
