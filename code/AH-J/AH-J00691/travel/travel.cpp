#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    //小 R 的车票上的车厢号、座位号,以及小 X 的车票上的车厢号、座位号
    if(c1==c2) printf("1");
    else {printf("0000");return 0;}
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        printf("1");
        LL a=s1[2]-'A'+1,b=s2[2]-'A'+1;
        if((a>=4&&b>=4)||(a<=3&&b<=3)) {
            printf("1");
            if(abs(a-b)==1) printf("1");
            else printf("0");
        }else printf("00");
    }else printf("000");
    return 0;
}
