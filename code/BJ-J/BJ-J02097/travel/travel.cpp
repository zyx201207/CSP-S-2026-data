#include<bits/stdc++.h>
using namespace std;

char a[3],b[3],c[3],d[3];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",a,b,c,d);
    // printf("OK");
    int z=0;
    if(a[0]==c[0] && a[1]==c[1]) z=1;
    printf("%d",z);
    // printf("OK");
    if(z==0){
        printf("000\n");
        // printf("OK");
    }else{

        z=0;
        if(b[0]==d[0] && b[1]==d[1]) z=1;
        printf("%d",z);
        if(z==0){
            printf("00\n");
        }else{
            int x=b[2],y=d[2];
            // printf("%c%c",x,y);
            // z=0;
            if((x>='A'&&x<='C' && y>='D')||(y>='A'&&y<='C' && x>='D')){
                printf("00\n");
            }else{
                printf("1");
                if(x-y==1||x-y==-1){
                    printf("1\n");
                }else printf("0\n");
            }
        }
    }
    return 0;
    
}