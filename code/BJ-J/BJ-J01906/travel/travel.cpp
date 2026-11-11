#include<bits/stdc++.h>
using namespace std;
const int N=10;
char c1[N],s1[N],c2[N],s2[N];
bool check1(char a,char b){
    if(a>b) swap(a,b);
    if(a=='C'&&b=='D') return false;
    if(a+1==b) return true;
    if(a=='A'&&b=='C') return true;
    return false;
}
bool check2(char a,char b){
    if(a>b) swap(a,b);
    if(a=='C'&&b=='D') return false;
    if(a+1==b) return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",c1+1,s1+1,c2+1,s2+1);
    if(s1[3]=='F') s1[3]='E';
    if(s2[3]=='F') s2[3]='E';
    if(c1[1]==c2[1]&&c1[2]==c2[2]){
        printf("1");
        if(s1[1]==s2[1]&&s1[2]==s2[2]){
            printf("1");
            if(check1(s1[3],s2[3])){
                printf("1");
                if(check2(s1[3],s2[3])) printf("1");
                else printf("0");
            }
            else printf("00");
        }
        else printf("000");
    }
    else printf("0000");
    printf("\n");
    return 0;
}