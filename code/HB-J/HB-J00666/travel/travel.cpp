#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main ( ) {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    int m=0,n=0;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    if(b=="01A"){
        m=111;
    }else if(b=="01B"){
        m=112;
    }else if(b=="01C"){
        m=113;
    }else if(b=="01D"){
        m=125;
    }else if(b=="01F"){
        m=126;
    }else if(b=="02A"){
        m=211;
    }else if(b=="02B"){
        m=212;
    }else if(b=="02C"){
        m=213;
    }else if(b=="02D"){
        m=225;
    }else if(b=="02F"){
        m=226;
    }else if(b=="03A"){
        m=311;
    }else if(b=="03B"){
        m=312;
    }else if(b=="03C"){
        m=313;
    }else if(b=="03D"){
        m=325;
    }else if(b=="03F"){
        m=326;
    }else if(b=="04A"){
        m=411;
    }else if(b=="04B"){
        m=412;
    }else if(b=="04C"){
        m=413;
    }else if(b=="04D"){
        m=425;
    }else if(b=="04F"){
        m=426;
    }else if(b=="05A"){
        m=511;
    }else if(b=="05B"){
        m=512;
    }else if(b=="05C"){
        m=513;
    }else if(b=="05D"){
        m=525;
    }else if(b=="05F"){
        m=526;
    }else if(b=="06A"){
        m=611;
    }else if(b=="06B"){
        m=612;
    }else if(b=="06C"){
        m=613;
    }else if(b=="06D"){
        m=625;
    }else if(b=="06F"){
        m=626;
    }else if(b=="07A"){
        m=711;
    }else if(b=="07B"){
        m=712;
    }else if(b=="07C"){
        m=713;
    }else if(b=="07D"){
        m=725;
    }else if(b=="07F"){
        m=726;
    }else if(b=="08A"){
        m=811;
    }else if(b=="08B"){
        m=812;
    }else if(b=="08C"){
        m=813;
    }else if(b=="08D"){
        m=825;
    }else if(b=="08F"){
        m=826;
    }else if(b=="09A"){
        m=911;
    }else if(b=="09B"){
        m=912;
    }else if(b=="09C"){
        m=913;
    }else if(b=="09D"){
        m=925;
    }else if(b=="09F"){
        m=926;
    }else if(b=="10A"){
        m=1011;
    }else if(b=="10B"){
        m=1012;
    }else if(b=="10C"){
        m=1013;
    }else if(b=="10D"){
        m=1025;
    }else if(b=="10F"){
        m=1026;
    }else if(b=="11A"){
        m=1111;
    }else if(b=="11B"){
        m=1112;
    }else if(b=="11C"){
        m=1113;
    }else if(b=="11D"){
        m=1125;
    }else if(b=="11F"){
        m=1126;
    }else if(b=="12A"){
        m=1211;
    }else if(b=="12B"){
        m=1212;
    }else if(b=="12C"){
        m=1213;
    }else if(b=="12D"){
        m=1225;
    }else if(b=="12F"){
        m=1226;
    }else if(b=="13A"){
        m=1311;
    }else if(b=="13B"){
        m=1312;
    }else if(b=="13C"){
        m=1313;
    }else if(b=="13D"){
        m=1325;
    }else if(b=="13F"){
        m=1326;
    }else if(b=="14A"){
        m=1411;
    }else if(b=="14B"){
        m=1412;
    }else if(b=="14C"){
        m=1413;
    }else if(b=="14D"){
        m=1425;
    }else if(b=="14F"){
        m=1426;
    }else if(b=="15A"){
        m=1511;
    }else if(b=="15B"){
        m=1512;
    }else if(b=="15C"){
        m=1513;
    }else if(b=="15D"){
        m=1525;
    }else if(b=="15F"){
        m=1526;
    }else if(b=="16A"){
        m=1611;
    }else if(b=="16B"){
        m=1612;
    }else if(b=="16C"){
        m=1613;
    }else if(b=="16D"){
        m=1625;
    }else if(b=="16F"){
        m=1626;
    }else if(b=="17A"){
        m=1711;
    }else if(b=="17B"){
        m=1712;
    }else if(b=="17C"){
        m=1713;
    }else if(b=="17D"){
        m=1725;
    }else if(b=="17F"){
        m=1726;
    }else if(b=="18A"){
        m=1811;
    }else if(b=="18B"){
        m=1812;
    }else if(b=="18C"){
        m=1813;
    }else if(b=="18D"){
        m=1825;
    }else if(b=="18F"){
        m=1826;
    }
    if(d=="01A"){
        n=111;
    }else if(d=="01B"){
        n=112;
    }else if(d=="01C"){
        n=113;
    }else if(d=="01D"){
        n=125;
    }else if(d=="01F"){
        n=126;
    }else if(d=="02A"){
        n=211;
    }else if(d=="02B"){
        n=212;
    }else if(d=="02C"){
        n=213;
    }else if(d=="02D"){
        n=225;
    }else if(d=="02F"){
        n=226;
    }else if(d=="03A"){
        n=311;
    }else if(d=="03B"){
        n=312;
    }else if(d=="03C"){
        n=313;
    }else if(d=="03D"){
        n=325;
    }else if(d=="03F"){
        n=326;
    }else if(d=="04A"){
        n=411;
    }else if(d=="04B"){
        n=412;
    }else if(d=="04C"){
        n=413;
    }else if(d=="04D"){
        n=425;
    }else if(d=="04F"){
        n=426;
    }else if(d=="05A"){
        n=511;
    }else if(d=="05B"){
        n=512;
    }else if(d=="05C"){
        n=513;
    }else if(d=="05D"){
        n=525;
    }else if(d=="05F"){
        n=526;
    }else if(d=="06A"){
        n=611;
    }else if(d=="06B"){
        n=612;
    }else if(d=="06C"){
        n=613;
    }else if(d=="06D"){
        n=625;
    }else if(d=="06F"){
        n=626;
    }else if(d=="07A"){
        n=711;
    }else if(d=="07B"){
        n=712;
    }else if(d=="07C"){
        n=713;
    }else if(d=="07D"){
        n=725;
    }else if(d=="07F"){
        n=726;
    }else if(d=="08A"){
        n=811;
    }else if(d=="08B"){
        n=812;
    }else if(d=="08C"){
        n=813;
    }else if(d=="08D"){
        n=825;
    }else if(d=="08F"){
        n=826;
    }else if(d=="09A"){
        n=911;
    }else if(d=="09B"){
        n=912;
    }else if(d=="09C"){
        n=913;
    }else if(d=="09D"){
        n=925;
    }else if(d=="09F"){
        n=926;
    }else if(d=="10A"){
        n=1011;
    }else if(d=="10B"){
        n=1012;
    }else if(d=="10C"){
        n=1013;
    }else if(d=="10D"){
        n=1025;
    }else if(d=="10F"){
        n=1026;
    }else if(d=="11A"){
        n=1111;
    }else if(d=="11B"){
        n=1112;
    }else if(d=="11C"){
        n=1113;
    }else if(d=="11D"){
        n=1125;
    }else if(d=="11F"){
        n=1126;
    }else if(d=="12A"){
        n=1211;
    }else if(d=="12B"){
        n=1212;
    }else if(d=="12C"){
        n=1213;
    }else if(d=="12D"){
        n=1225;
    }else if(d=="12F"){
        n=1226;
    }else if(d=="13A"){
        n=1311;
    }else if(d=="13B"){
        n=1312;
    }else if(d=="13C"){
        n=1313;
    }else if(d=="13D"){
        n=1325;
    }else if(d=="13F"){
        n=1326;
    }else if(d=="14A"){
        n=1411;
    }else if(d=="14B"){
        n=1412;
    }else if(d=="14C"){
        n=1413;
    }else if(d=="14D"){
        n=1425;
    }else if(d=="14F"){
        n=1426;
    }else if(d=="15A"){
        n=1511;
    }else if(d=="15B"){
        n=1512;
    }else if(d=="15C"){
        n=1513;
    }else if(d=="15D"){
        n=1525;
    }else if(d=="15F"){
        n=1526;
    }else if(d=="16A"){
        n=1611;
    }else if(d=="16B"){
        n=1612;
    }else if(d=="16C"){
        n=1613;
    }else if(d=="16D"){
        n=1625;
    }else if(d=="16F"){
        n=1626;
    }else if(d=="17A"){
        n=1711;
    }else if(d=="17B"){
        n=1712;
    }else if(d=="17C"){
        n=1713;
    }else if(d=="17D"){
        n=1725;
    }else if(d=="17F"){
        n=1726;
    }else if(d=="18A"){
        n=1811;
    }else if(d=="18B"){
        n=1812;
    }else if(d=="18C"){
        n=1813;
    }else if(d=="18D"){
        n=1825;
    }else if(d=="18F"){
        n=1826;
    }
    if(m/100==n/100){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    if(m/10%10==n/10%10){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if(abs(m%10-n%10)==1){
        cout<<"1";
    }else{
        cout<<"0";
    }
 return 0;
}