#include <bits/stdc++.h>
using namespace std;
struct s{
    int r[2];
    int l[2];
    char t;
};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    s xr,xx;
    int r,x;
    scanf("%2d %2d%c",&xr.r,&xr.l,&xr.t);
    scanf("%2d %2d%c",&xx.r,&xx.l,&xx.t);
    if(xr.t<='C')
        r=1;
    else r=2;
    if(xx.t<='C')
        x=1;
    else x=2;
    if(xr.r[0]==xx.r[0]&&xr.r[1]==xx.r[1]){
       printf("1");
       if(xr.l[0]==xx.l[0]&&xr.l[1]==xx.l[1]){
         printf("1");
         if(r==x){
            printf("1");
            if(xr.t+1==xx.t&&xr.t!='C'||xr.t-1==xx.t&&xr.t!='D')
                printf("1");
            else  printf("0");
         }
         else  printf("00");
       }
    else  printf("000");
    }
    else  printf("0000");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
