#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s[4]={};
    cin>>s[0]>>s[1]>>s[2]>>s[3];
    if(s[0]==s[2]){
        printf("1");
    }else{
        printf("0000");
        return 0;
    }
    int ans=(s[1][0]-'0')*10+s[1][1]-'0';
    int mun=(s[3][0]-'0')*10+s[3][1]-'0';
    if(ans==mun){
        printf("1");
    }else{
        printf("000");
        return 0;
    }
    if((s[1][2]>='A'&&s[1][2]<='C'&&s[3][2]>='A'&&s[3][2]<='C')||((s[1][2]=='D'&&s[3][2]=='F')||(s[3][2]=='D'&&s[1][2]=='F'))){
        printf("1");
    }else{
        printf("00");
        return 0;
    }
    if(s[1][2]+1==s[3][2]||s[1][2]-1==s[3][2]){
        printf("1");
    }else if(s[1][2]=='D'&&s[3][2]=='F'||s[3][2]=='D'&&s[1][2]=='F'){
        printf("1");
    }else{
        printf("0");
        return 0;
    }
    return 0;
}
