#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) printf("0000");
    else{
        printf("1");
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            printf("1");
            if(s1[2]=='A'){
                if(s2[2]=='B') printf("11");
                else if(s2[2]=='C') printf("10");
                else printf("00");
            }else if(s1[2]=='B'){
                if(s2[2]=='A'||s2[2]=='C') printf("11");
                else printf("00");
            }else if(s1[2]=='C'){
                if(s2[2]=='B') printf("11");
                else if(s2[2]=='A') printf("10");
                else printf("00");
            }else if(s1[2]=='D'){
                if(s2[2]=='F') printf("11");
                else printf("00");
            }else{
                if(s2[2]=='D') printf("11");
                else printf("00");
            }
        }
        else printf("000");
    }
    return 0;
}