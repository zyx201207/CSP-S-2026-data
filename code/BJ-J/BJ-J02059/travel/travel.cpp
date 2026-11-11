#include<bits/stdc++.h>
using namespace std;
string ans="";
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int taba,tabb,linea,lineb;
    char seata,seatb;
    string tra="  ",sea="  ";
    string trb="  ",seb="  ";
    cin>>tra>>sea>>trb>>seb;
    char a=sea[2],b=seb[2];
    sea.resize(2),seb.resize(2);
    if(tra==trb) ans+="1";
    else {ans+="0000";cout<<ans;return 0;}
    if(sea==seb) ans+="1";
    else {ans+="000";cout<<ans;return 0;}
    if(('A'<=a&&a<='C'&&'A'<=b&&b<='C')||('D'<=a&&a<='E'&&'D'<=b&&b<='E')) ans+="1";
    else {ans+="00";cout<<ans;return 0;}
    if((a=='C'&&b=='B')||(a=='A'&&b=='B')||(a=='B'&&(b=='A'||b=='C'))||(a=='D'&&b=='E')||(a=='D'&&b=='E')) ans+="1";
    else {ans+="0";cout<<ans;return 0;}
    cout<<ans<<"\n";
    return 0;
}
