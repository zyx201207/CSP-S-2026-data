#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2)
        cout<<"1";
    else
    {
        cout<<"0000";
        return 0;
    }
    if(y1[0]==y2[0]&&y1[1]==y2[1])
        cout<<"1";
    else
    {
        cout<<"000";
        return 0;
    }
    if((y1[2]=='A'&&y2[2]=='B')||(y1[2]=='A'&&y2[2]=='C')||(y1[2]=='B'&&y2[2]=='C')||(y1[2]=='B'&&y2[2]=='A')||(y1[2]=='C'&&y2[2]=='A')||(y1[2]=='C'&&y2[2]=='B')||(y1[2]=='D'&&y2[2]=='F')||(y1[2]=='F'&&y2[2]=='D'))
        cout<<"1";
    else
    {
        cout<<"00";
        return 0;
    }
    if((y1[2]=='A'&&y2[2]=='B')||(y1[2]=='B'&&y2[2]=='C')||(y1[2]=='B'&&y2[2]=='A')||(y1[2]=='C'&&y2[2]=='B')||(y1[2]=='D'&&y2[2]=='F')||(y1[2]=='F'&&y2[2]=='D'))
        cout<<"1";
    else
    {
        cout<<"0";
        return 0;
    }
    return 0;
}
