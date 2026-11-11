#include <iostream>
using namespace std;
int main()
{freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int c1;
int c2;
char s1[3];
char s2[3];
cin>>c1>>s1[0]>>s1[1]>>s1[2]>>c2>>s2[0]>>s2[1]>>s2[2];
if (c1==c2)
cout<<"1";
if (c1!=c2)
{cout<<"0000";
return 0;}

if (s1[0]==s2[0])
{if (s1[1]==s2[1])
cout<<"1";
if (s1[1]!=s2[1])
{cout<<"000";
return 0;}
}
if (s1[2]>'C' && s1[2]<'G' && s2[2]>='A' && s2[2]<'D')
{
    cout<<"00";

}
if (s1[2]>='A' && s1[2]<'D' && s2[2]>'C' && s2[2]<='G' )
{
    cout<<"00";


}
if (s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F')
{
    cout<<"1";
    cout<<"1";
}
if (s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C')
{
    cout<<"1";
    if (s2[2]==s1[2]+1 || s2[2]==s1[2]-1)
        cout<<"1";
    if (s2[2]!=s1[2]+1 && s2[2]!=s1[2]-1)
        cout<<"0";

}
return 0;

}





