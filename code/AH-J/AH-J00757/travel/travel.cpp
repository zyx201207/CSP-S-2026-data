#include<bits/stdc++.h>
using namespace std;
string cR,sR,cX,sX;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cR>>sR>>cX>>sX;
    if(cR==cX)cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    if(sR[0]==sX[0]&&sR[1]==sX[1])cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if( ( (sR[2]=='A'||sR[2]=='B'||sR[2]=='C')&&(sX[2]=='A'||sX[2]=='B'||sX[2]=='C') ) || ( (sR[2]=='D'||sR[2]=='F')&&(sR[2]=='D'||sR[2]=='F') ) )cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    if((sR[2]=='A'&&sX[2]=='B')||(sR[2]=='B'&&sX[2]=='A')||(sR[2]=='C'&&sX[2]=='B')||(sR[2]=='B'&&sX[2]=='C')||(sR[2]=='D'&&sX[2]=='F')||(sR[2]=='F'&&sX[2]=='D'))cout<<1;
    else cout<<0;
    return 0;
}//red
