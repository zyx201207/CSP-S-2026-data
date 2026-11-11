#include<cstdio>
using namespace std;
char s1[10],s2[10],c;
int ls,c1,c2;
FILE *p;
bool same(){
    if(s1[2]<='C'&&s2[2]>='D')return 0;
    if(s1[2]>='D'&&s2[2]<='C')return 0;
    return 1;
}
bool SAME(){
    if(s1[2]-s2[2]==1)return 1;
    if(s1[2]-s2[2]==-1)return 1;
    return 0;
}
int main(){
    p=freopen("travel.in","r",stdin);
    p=freopen("travel.out","w",stdout);
    ls=scanf("%d%s%d%s",&c1,s1,&c2,s2);
    //printf("%d %s %d %s",c1,s1,c2,s2);
    if(c1==c2){
        printf("1");
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            printf("1");
            if(same()){
                printf("1");
                if(SAME()){
                    printf("1");
                }
                else {printf("0");}
            }
            else {printf("00");}
        }
        else {printf("000");}
    }
    else {printf("0000");}
    return 0;
}