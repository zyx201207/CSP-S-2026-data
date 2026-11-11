#include<bits/stdc++.h>
using namespace std;
string c1,z1,c2,z2;
bool tc(char a,char b){
    if(a=='A'){
        return b=='B'||b=='C';
    }
    if(a=='B'){
        return b=='A'||b=='C';
    }
    if(a=='C'){
        return b=='A'||b=='B';
    }
    if(a=='D'){
        return b=='F';
    }
    if(a=='F'){
        return b=='D';
    }
}
bool xl(char a,char b){
    if(a=='D'||a=='F'||a=='B') return true;
    if(a=='C') return b=='B';
    if(a=='A') return b=='B';
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>z1>>c2>>z2;
    if(c1!=c2){
        printf("0000");
    }else{
        printf("1");
        if(z1.substr(0,2)!=z2.substr(0,2)){
            printf("000");
        }else{
            printf("1");
            if(!tc(z1[2],z2[2])){
                printf("00");
            }else{
                printf("1");
                if(xl(z1[2],z2[2])){
                    printf("1");
                }else{
                    printf("0");
                }
            }
        }
    }
    return 0;
}
