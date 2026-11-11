#include<bits/stdc++.h>
using namespace std;
int main(){
    fstream fi,fo;
    fi.open("travel.in");fo.open("travel.out");
    int c1,c2;
    string s1,s2;
    fi>>c1>>s1>>c2>>s2;
    int sc1=((int)(s1[0]-'0'))*10+((int)(s1[1]-'0')),sc2=((int)(s2[0]-'0'))*10+((int)(s2[1]-'0'));
    int ss1=s1[2]-'A',ss2=s2[2]-'A';//ABCDF->01235
    if(ss1==5)ss1--;if(ss2==5)ss2--;//ABCDF->01234

    //两张车票对应的座位是否在同一节车厢
    if(c1==c2)fo<<1;
    else{fo<<"0000";return 0;};

    //两张车票对应的座位是否在同一节车厢的同一排
    if(sc1==sc2)fo<<1;
    else{fo<<"000";return 0;};

    //且位于过道的同一侧
    if((0<=ss1&&ss1<=2&&0<=ss2&&ss2<=2)||(3<=ss1&&ss1<=4&&3<=ss2&&ss2<=4))fo<<1;
    else{fo<<"00";return 0;};

    //两张车票对应的座位是否相邻
    fo<<(abs(ss1-ss2)==1);

    return 0;
}
