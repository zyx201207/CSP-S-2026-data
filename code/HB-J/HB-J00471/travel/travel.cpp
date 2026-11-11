#include<bits/stdc++.h>
using namespace std;
char c1[3],s1[4],c2[3],s2[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",c1,s1,c2,s2);
    if(strcmp(c1,c2)==0)
        printf("1");
    else{
        printf("0000");
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])
        printf("1");
    else{
        printf("000");
        return 0;
    }
    if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))
        printf("1");
    else{
        printf("00");
        return 0;
    }
    if(abs(s1[1]-s2[1])==1||abs(s1[2]-s2[2])==1)
        printf("1");
    else
        printf("0");
    return 0;
}
