#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[5],s2[5];
int sit[5][5];


int main(){
    freopen("travel.in","r","stdin");
    freopen("travel.out","w","stdout");
    scanf("%d%s%d%s",&c1,s1,&c2,s2);
    int s1_ = (s1[0] - '0') * 10 + (s2[1] - '0'),s2_ = (s2[0] - '0') * 10 + (s2[1] - '0');
    char s1_nember = s1[2],s2_nember = s2[2];
    if(s1_nember == 'F'){
        s1_nember = 'E';
    }
    if(s2_nember == 'F'){
        s2_nember = 'E';
    }
    for(int i = 0;i <= 4;i++){
        for(int j = 0;j <= 4;j++){
            if((i < 3 && j < 3) || (i > 2&&j > 2)){
                sit[i][j] = 1;
            }
        }
    }
    if(c1 == c2){
        printf("%d",1);
        if(s1_ == s2_){
            printf("%d",1);
            if(sit[s1_nember - 'A'][s2_nember - 'A'] == 1){
                printf("%d",1);
                if(abs(s1_nember - s2_nember) == 1){
                    printf("%d",1);
                }
                else{
                    printf("%d",0);
                }
            }else{
                printf("%d",0);
                printf("%d",0);
            }
        }else{
            printf("%d",0);
            printf("%d",0);
            printf("%d",0);
        }
    }else{
        printf("%d",0);
        printf("%d",0);
        printf("%d",0);
        printf("%d",0);
    }
    return 0;
}