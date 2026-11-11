#include <bits/stdc++.h>
using namespace std;

char c1[5],s1[5],c2[5],s2[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",c1 + 1,s1 + 1,c2 + 1,s2 + 1);
    for(int i = 1;i <= 2;i++){
        if(c1[i] != c2[i]){
            printf("0000");
            return 0;
        }
    }
    for(int i = 1;i <= 2;i++){
        if(s1[i] != s2[i]){
            printf("1000");
            return 0;
        }
    }
    if(s1[3] - 'A' > 2 && s2[3] - 'A' <= 2){
        printf("1100");
        return 0;
    }else{
        if(s1[3] - 'A' <= 2 && s2[3] - 'A' > 2){
            printf("1100");
            return 0;
        }
    }
    if(abs(s1[3] - s2[3]) != 1){
        printf("1110");
        return 0;
    }
    printf("1111");
    return 0;
}
