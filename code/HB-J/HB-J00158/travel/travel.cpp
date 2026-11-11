#include<bits/stdc++.h>
using namespace std;
string c1,c2,z1,z2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>z1>>c2>>z2;
    if(c1[0]!=c2[0]||c1[1]!=c2[1])
    {
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if((z1[0]==z2[0])&&(z1[1]==z2[1]))
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if((z1[2]=='A'&&z2[2]=='B')||(z1[2]=='A'&&z2[2]=='C')||(z1[2]=='B'&&z2[2]=='A')||(z1[2]=='B'&&z2[2]=='C')||(z1[2]=='C'&&z2[2]=='A')||(z1[2]=='C'&&z2[2]=='B')||(z1[2]=='D'&&z2[2]=='F')||(z1[2]=='F'&&z2[2]=='D'))
        cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    if((z1[2]=='A'&&z2[2]=='B')||(z1[2]=='B'&&z2[2]=='A')||(z1[2]=='B'&&z2[2]=='C')||(z1[2]=='D'&&z2[2]=='F')||(z1[2]=='C'&&z2[2]=='B')||(z1[2]=='F'&&z2[2]=='D'))
        cout<<1;
    else
        cout<<0;
    return 0;
}
