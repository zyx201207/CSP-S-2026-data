#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool ss(char a,char b){
    if(a > b){
        swap(a,b);
    }
    if((a == 'A' && (b == 'B' || b == 'C')) || (a == 'B' && b == 'C')){
        return true;
    }
    if(a == 'D' && b == 'F'){
        return true;
    }
    return false;
}

bool nx(char a,char b){
    if(a > b){
        swap(a,b);
    }
    if(b == a + 1){
        return true;
    }
    return false;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2;
    int a,b;
    char c[4],d[4];
    cin >> s1;
    scanf("%s",c);
    cin >> s2;
    scanf("%s",d);
    if(s1 != s2){
        printf("0000\n");
        return 0;
    }
    if(s1 == s2){
        printf("1");
    }
    //car
    if(c[0] == d[0] && c[1] == d[1]){
        printf("1");
    }else{
        printf("000\n");
        return 0;
    }
    //row
    if(ss(c[2],d[2])){
        printf("1");
    }else{
        printf("00\n");
        return 0;
    }
    //same side
    if(nx(c[2],d[2])){
        printf("1\n");
    }else{
        printf("0\n");
    }
    return 0;
}
