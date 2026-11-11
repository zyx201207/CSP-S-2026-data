#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int mj=0,jm=0,mjj=0,mjm=0;
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c)
    {
    cout<<"1";
    mj++;
    }

    if(a!=c)
    {
        cout<<"0";
    }
    if(b[0]==d[0]&&b[1]==d[1])
    {
        if(mj==1){
    cout<<"1";
     jm++;
    }
    }
    if(jm==0)
    {
        cout<<"0";
    }

    if(b[2]=='D'||b[2]=='F')
    {
    if(d[2]=='D'||d[2]=='F')
    {
        if(jm==1&&mj==1)
        {
    cout<<"1";
    mjj++;
    }
    }
    }

    if(b[2]==d[2]-1||b[2]==d[2]+1)
    {
        if(mjj==1){
    cout<<"1";
    mjm++;
        }
    }

     if(b[2]=='A'||b[2]=='B'||b[2]=='C')
    {
    if(d[2]=='A'||d[2]=='B'||d[2]=='C')
    {
        if(mj==1&&jm==1)
        {
            cout<<"1";
    mjj++;
        }

    }
    }

    if(mjj==0)
    {
        cout<<"0";
    }
    if(b[2]==d[2]-1||b[2]==d[2]+1)
    {
        if(mjj==1&&mjm==0){
      mjm++;
    cout<<"1";
        }
    }
    if(mjm==0)
    {

        cout<<"0";
    }


    return 0;
}
