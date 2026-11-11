#include<bits/stdc++.h>
using namespace std;
char c1[114],c2[114],s1[114],s2[114];
int b1=0,b2=0,b3=0,b4=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",c1+1,s1+1,c2+1,s2+1);
    if(c1[1]==c2[1] && c1[2]==c2[2]){
        printf("1");
        if(s1[1]==s2[1] && s1[2]==s2[2]){
            printf("1");
            if((s1[3]>='A' && s1[3]<='C')&&(s2[3]>='A' && s2[3]<='C')){
                printf("1");
                if(abs(s1[3]-s2[3])==1){
                    printf("1\n");
                }else printf("0\n");
            }else if((s1[3]>='D' && s1[3]<='F')&&(s2[3]>='D' && s2[3]<='F')){
                printf("11\n");
            }else printf("00\n");
        }else printf("000\n");
    }else printf("0000\n");
}
