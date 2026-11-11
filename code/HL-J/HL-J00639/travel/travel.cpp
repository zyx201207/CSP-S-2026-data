#include<bits/stdc++.h>
using namespace std;
char c1[10],c,s1[10],c2[10],s2[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%c%c%c%c%c%c%c%c%c%c%c%c%c",&c1[1],&c1[2],&c,&s1[1],&s1[2],&s1[3],&c,&c2[1],&c2[2],&c,&s2[1],&s2[2],&s2[3]);
    if(c1[1]==c2[1]&&c1[2]==c2[2]){
        printf("1");
        if(s1[1]==s2[1]&&s1[2]==s2[2]){
            printf("1");
            if((s1[3]<='C'&&s2[3]<='C')||(s1[3]>'C'&&s2[3]>'C')){
                printf("1");
                if(s1[3]+1==s2[3]||s1[3]-1==s2[3])
                    printf("1");
                else printf("0");
            }
            else printf("00");
        }
        else printf("000");
    }
    else printf("0000");
    return 0;
}
