#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int a[4],b[4];
int main()
{
    freopen(travel.in,"r",stdin);
    freopen(travel.out,"w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1)cout<<1;
    else cout<<0;
    if(a2[0]==b2[0]&&a2[1]==b2[1])cout<<1;
    else cout<<0;
    if(a2[2]=='A'&&b2[2]=='B'||a2[2]=='B'&&b2[2]=='A') cout<<1;
    else if(a2[2]=='C'&&b2[2]=='B'||a2[2]=='B'&&b2[2]=='C')cout<<1;
    else if(a2[2]=='D'&&b2[2]=='E'||a2[2]=='E'&&b2[2]=='D')cout<<1;
    else cout<<0;
    if(a2[2]=='A'&&b2[2]=='B'||a2[2]=='B'&&b2[2]=='A') cout<<1;
    else if(a2[2]=='C'&&b2[2]=='B'||a2[2]=='B'&&b2[2]=='C')cout<<1;
    else if(a2[2]=='D'&&b2[2]=='E'||a2[2]=='E'&&b2[2]=='D')cout<<1;
    else cout<<0;



}
