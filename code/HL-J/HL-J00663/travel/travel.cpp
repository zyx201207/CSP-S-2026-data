#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
bool a,b,c;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",c1,s1,c2,s2);
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        printf("1");
        a=true;
    }else{
        printf("0");
        a = false;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&a==true){
        printf("1");
        b = true;
    }else{
        printf("0");
        b = false;
    }
    if( ( ((s1[2]=='A'||s1[2]=='B'||s1[2]=='C') && (s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))  ||  ((s1[2]=='D'||s1[2]=='F') && (s2[2]=='D'||s2[2]=='F')) ) &&(a==true&&b==true)){
        printf("1");
        c = true;
    }else{
        printf("0");
        c = false;
    }
    if( abs(int(s1[2])-int(s2[2])) == 1 &&(a==true&&b==true&&c==true)){
        printf("1");
    }else{
        printf("0");
    }
    return 0;
}
