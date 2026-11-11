#include<bits/stdc++.h>
using namespace std;
string a,b,a2,b2;
struct Node{
    int x,y;
}t[105];
int in=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>a2>>b2;
    t[1]={(b[0]-'0')*10+b[1]-'0',b[2]-'A'+1};
    t[2]={(b2[0]-'0')*10+b2[1]-'0',b2[2]-'A'+1};
    if(a==a2){
        printf("1");
        if(t[1].x==t[2].x){
            printf("1");
            if((t[1].y<=3&&t[2].y<=3)||(t[1].y>=4&&t[2].y>=4)){
                printf("1");
                if(t[1].x+1==t[2].x||t[1].x-1==t[2].x){
                    printf("1");
                }else{
                    printf("0");
                }
            }else{
                printf("00");
            }
        }else{
            printf("000");
        }
    }else{
        printf("0000");
    }
    return 0;
}
