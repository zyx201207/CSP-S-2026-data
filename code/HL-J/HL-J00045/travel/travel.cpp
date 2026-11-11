#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    int c11,c12,c21,c22,c31,c32,c41,c42;
    cin>>c1>>c2>>c3>>c4;
    c11=c1[0]-'0'*10+c1[1]-'0';
    c21=c2[0]-'0'*10+c2[1]-'0';
    c31=c3[0]-'0'*10+c3[1]-'0';
    c41=c4[0]-'0'*10+c4[1]-'0';
    bool ans=false;
    if(c2[2]=='A' && c4[2]=='B' || c4[2]=='A' && c2[2]=='B' || c2[2]=='C' && c4[2]=='B' || c4[2]=='C' && c2[2]=='B' || c2[2]=='D' && c4[2]=='F' || c4[2]=='D' && c2[2]=='F' )
    {
        ans=true;
    }
    else
    {
        ans=false;
    }

    if(c11==c31)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }

    if(c11==c31 && c21==c41)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }

    if(c11==c31 && c21==c41 && ((c2[2]=='A' || c2[2]=='B' || c2[2]=='C') && (c4[2]=='A' || c4[2]=='B' || c4[2]=='C')) || ((c2[2]=='D' || c2[2]=='F') && (c4[2]=='D' || c4[2]=='F')))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }

    if(c11==c31 && c21==c41 && ((c2[2]=='A' || c2[2]=='B' || c2[2]=='C') && (c4[2]=='A' || c4[2]=='B' || c4[2]=='C')) || ((c2[2]=='D' || c2[2]=='F') && (c4[2]=='D' || c4[2]=='F')) && ans)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
