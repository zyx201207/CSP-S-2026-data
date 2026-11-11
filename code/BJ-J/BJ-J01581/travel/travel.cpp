#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        printf("1");
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            printf("1");
            if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
                printf("1");
                if(abs((s1[2]-'0')-(s2[2]-'0'))==1){
                    printf("1");
                }else{
                    printf("0");
                }
            }else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
                printf("11");
            }else{
                printf("00");
            }
        }else{
            printf("000");
        }
    }else{
        printf("0000");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
