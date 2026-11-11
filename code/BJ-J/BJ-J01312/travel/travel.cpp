#include<bits/stdc++.h>
using namespace std;
char op1[10],seat1[10],op2[10],seat2[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>(op1+1)>>(seat1+1)>>(op2+1)>>(seat2+1);
    if((op1[1]!=op2[1])||(op1[2]!=op2[2]))
    {
        cout<<"0000\n";
        return 0;
    }
    if((seat1[1]!=seat2[1])||(seat1[2]!=seat2[2]))
    {
        cout<<"1000\n";
        return 0;
    }
    if(seat1[3]=='D')
    {
        if(seat2[3]!='F') cout<<"1100\n";
        else cout<<"1111\n";
        return 0;
    }
    if(seat1[3]=='F')
    {
        if(seat2[3]!='D') cout<<"1100\n";
        else cout<<"1111\n";
        return 0;
    }
    if(seat1[3]=='A')
    {
        if(seat2[3]=='B') cout<<"1111\n";
        else if(seat2[3]=='C') cout<<"1110\n";
        else cout<<"1100\n";
        return 0;
    }
    if(seat1[3]=='B')
    {
        if((seat2[3]=='A')||(seat2[3]=='C')) cout<<"1111\n";
        else cout<<"1100\n";
        return 0;
    }
    if(seat2[3]=='B') cout<<"1111\n";
    else if(seat2[3]=='A') cout<<"1110\n";
    else cout<<"1100\n";
    return 0;
}
