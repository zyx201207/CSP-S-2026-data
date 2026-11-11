#include<iostream>
using namespace std;

string c1,s1,c2,s2;

int main()
{
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
    }else
    {
        cout<<"0";
    }
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
    {
        cout<<"1";
    }else
    {
        cout<<"0";
    }
    char a=s1[2],b=s2[2];
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(('A'<=a&&a<='C'&&'A'<=b&&b<='C')||('D'<=a&&a<='F'&&'D'<=b&&b<='F')))
    {
        cout<<"1";
    }else
    {
        cout<<"0";
    }
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='B'&&b=='A')||(a=='C'&&b=='B')||(a=='D'&&b=='F')||(a=='F'&&b=='D')))
    {
        cout<<"1";
    }else
    {
        cout<<"0";
    }
    return 0;
}
