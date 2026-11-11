#include<bits/stdc++.h>
using namespace std;
int rcar,xcar;
string rs,xs;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d",&rcar);
    cin>>rs;
    scanf("%d",&xcar);
    cin>>xs;
    if(rcar==xcar){
        printf("1");
        if(rs[0]==xs[0]&&rs[1]==xs[1]){
            printf("1");
            if((rs[2]=='D'&&xs[2]=='F')||(xs[2]=='D'&&rs[2]=='F'))
                printf("11");
            else{
                if((rs[2]=='A'&&xs[2]=='C')||(xs[2]=='A'&&rs[2]=='C'))
                    printf("10");
                else{
                    if((rs[2]>='D'&&xs[2]<='C')||(xs[2]>='D'&&rs[2]<='C'))
                        printf("00");
                    else printf("11");
                }
            }
        }
        else printf("000");
    }
    else printf("0000");
    printf("\n");
}