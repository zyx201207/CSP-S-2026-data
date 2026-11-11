#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s1,s2,r1,r2;
bool check(char x,char y){
    if(x=='D'){
        return y=='F';
    }
    if(x=='F'){
        return y=='D';
    }
    if(y=='D'){
        return x=='F';
    }
    if(y=='F'){
        return x=='D';
    }
    return true;
}
bool check2(char x,char y){
    if(x=='D'||x=='F'){
        return true;
    }
    else{
        return abs(x-y)==1;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>r1>>r2;
    if(s1!=r1){
        printf("0000");
        return 0;
    }
    string tmp1=s2.substr(0,2),tmp2=r2.substr(0,2);
    if(tmp1!=tmp2){
        printf("1000");
        return 0;
    }
    char seat1=s2[2],seat2=r2[2];
    if(!check(seat1,seat2)){
        printf("1100");
        return 0;
    }
    if(!check2(seat1,seat2)){
        printf("1110");
        return 0;
    }
    printf("1111");
    return 0;
}
