#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf(" %s %s %s %s",c1,s1,c2,s2);
    if(c1[0] == c2[0]&&c1[1] == c2[1]){
        if(s1[0] == s2[0]&&s1[1] == s2[1]){
            if((s1[2] >= 'D'&&s2[2] >= 'D')||(s1[2] <= 'C'&&s2[2] <= 'C')){
                int b = s1[2] - s2[2];
                if(abs(b) == 1){
                    printf("1111");
                }else{
                    printf("1110");
                }
            }else{
                printf("1100");
            }
        }else{
            printf("1000");
        }
    }else{
        printf("0000");
    }
    return 0;
}
