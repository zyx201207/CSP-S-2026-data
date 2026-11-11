#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int change(char x){
    if(x=='A')return 1;
    if(x=='B')return 2;
    if(x=='C')return 3;
    if(x=='D')return 4;
    if(x=='F')return 5;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        printf("1");
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            printf("1");
            int a=change(s1[2]);
            int b=change(s2[2]);
            if((a<=3&&b<=3)||(a>=4&&b>=4)){
                printf("1");
                if(abs(a-b)==1)printf("1");
                else printf("0");
            }
            else printf("00");
        }
        else printf("000");
    }
    else printf("0000");
    return 0;
}
