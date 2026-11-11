#include<bits/stdc++.h>
using namespace std;
bool flag=true;
struct p{
    string c;
    string s;
}a,b;
int main(){
    freopen("travel.in","r",stdin);   freopen("travel.out","w",stdout);
    cin>>a.c>>a.s>>b.c>>b.s;
    if(a.c==b.c){
        printf("1");
    }else{
        printf("0000");
        return 0;
    }
    if(a.s[0]==b.s[0]&&a.s[1]==b.s[1]){
        printf("1");
    }else{
         printf("000");
         return 0;
    }
    if((a.s[2]-'A'<3 && b.s[2]-'A'<3) || (a.s[2]-'A'>2 && b.s[2]-'A'>2)){
        printf("1");
    }else{
        printf("0");
    }
    if(a.s[2]=='F'&&b.s[2]=='D'||a.s[2]=='D'&&b.s[2]=='F'){
        printf("1");
    }else{
       if(a.s[2]=='C'&&b.s[2]=='D'||a.s[2]=='D'&&b.s[2]=='C'){
            printf("0");
            
       }else{
           if(a.s[2]=='C'&&b.s[2]=='B'||a.s[2]=='B'&&b.s[2]=='C'){
            printf("1");
          }else{
            if(a.s[2]=='A'&&b.s[2]=='B'||a.s[2]=='B'&&b.s[2]=='A'){
                printf("1");
            }else{
                printf("0");
            }
          }
       }
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}