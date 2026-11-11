#include<bits/stdc++.h>

using namespace std;

char ca[5],sa[5],cb[5],sb[5];
int c1,s1,c2,s2;
char t,f;

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",ca + 1,sa + 1,cb + 1,sb + 1);
    t = '1';
    f = '0';
    if(ca[1] == cb[1] && ca[2] == cb[2]){
        printf("%c",t);
    }else{
         printf("%c%c%c%c",f,f,f,f);
        return 0;
    }
    if(sa[1] == sb[1] && sa[2] == sb[2]){
        printf("%c",t);
    }else{
         printf("%c%c%c",f,f,f);
        return 0;
    }
    if((sa[3] <= 'c' && sb[3] <= 'c') || sa[3] >= 'D' && sb[3] >= 'D'){
        printf("%c",t);
    }else{
         printf("%c%c",f,f);
        return 0;
    }
    if((sa[3] + 1 == sb[3]) || (sa[3] - 1 == sb[3])){
        printf("%c",t);
    }else{
         printf("%c",f);
        return 0;
    }
    return 0;
}
