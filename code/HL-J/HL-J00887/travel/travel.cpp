#include<bits/stdc++.h>
using namespace std;
string rseat,xseat;
string rt,xt;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rt>>rseat>>xt>>xseat;
    //判断
    //同一节车厢
    if(rt==xt)printf("1");
    else{
        printf("0000");
        return 0;
    }
    //同一排
    if(rseat[0]==xseat[0]&&rseat[1]==xseat[1])printf("1");
    else{
        printf("000");
        return 0;
    }
    //过道同一侧
    if((rseat[2]>='A'&&rseat[2]<='C')&&(xseat[2]>='A'&&xseat[2]<='C'))printf("1");
    else if((rseat[2]>='D'&&rseat[2]<='E')&&(xseat[2]>='D'&&xseat[2]<='E'))printf("1");
    else {
        printf("00");
        return 0;
    }
    //相邻
    if(abs(int(rseat[2])-int(xseat[2]))==1)printf("1");
    else {
        printf("0");
        return 0;
    }
    return 0;
}
