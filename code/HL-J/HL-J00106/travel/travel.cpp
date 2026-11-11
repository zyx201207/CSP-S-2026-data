#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
string a,b,c,d;
cin>>a>>c>>b>>d;

if(a==b)
{

    cout<<1;
    if(c[0]==d[0]&&c[1]==d[1])
{
    cout<<1;
    if(((c[2]=='F')&&(d[2]=='D'))||((d[2]=='F')&&(c[2]=='D'))){cout<<11;}
    else if((c[2]=='A'&&d[2]=='B')||(d[2]=='A'&&c[2]=='B')){cout<<11;}
    else if((c[2]=='C'&&d[2]=='B')||(d[2]=='B'&&c[2]=='C')){cout<<11;}
    else if((c[2]=='C'&&d[2]=='A')||(d[2]=='A'&&c[2]=='C')){cout<<10;}
    else{cout<<0<<0;}

}
else
{

    cout<<0<<0<<0;
}
}
else
{

    cout<<0<<0<<0<<0;
}

return 0;}
