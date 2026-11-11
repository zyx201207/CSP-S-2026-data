#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll getll(){
    int f = 1;
    ll sum = 0;
    int c = getchar();

    while(c > '9' || c < '0'){
        if(c == '-'){
            f = -1;
        }
        c = getchar();
    }

    while(c >= '0' && c <= '9'){
        sum = sum * 10 + c - '0';
        c = getchar();
    }

    if(c != EOF){
        ungetc(c,stdin);
    }

    return sum*f;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ll c1 = getll();
    ll s1 = getll();
    char z1 = getchar();
    ll c2 = getll();
    ll s2 = getll();
    char z2 = getchar();

    if(c1 == c2){
        printf("1");
        if(s1 == s2){
            printf("1");
            if((z1 == 'D' && z2 == 'F') || (z2 == 'D' && z1 == 'F') ||
               (z1 >= 'A' && z1 <= 'C' && z2 >= 'A' && z2 <= 'C')){
                printf("1");
                if((z1 == 'D' && z2 == 'F') || (z2 == 'D' && z1 == 'F') ||
                   (z1 == 'A' && z2 == 'B') || (z2 == 'A' && z1 == 'B') ||
                   (z1 == 'B' && z2 == 'C') || (z2 == 'B' && z1 == 'C')){
                    printf("1");
                }
                else{
                    printf("0");
                }
            }
            else{
                printf("00");
            }
        }
        else{
            printf("000");
        }
    }
    else{
        printf("0000");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
