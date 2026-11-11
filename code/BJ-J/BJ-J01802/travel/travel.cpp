#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long c1=0,c2=0;
    string s1="",s2="";
    scanf("%d",&c1);
    cin>>s1;
    scanf("%d",&c2);
    cin>>s2;
    if(c1!=c2){
        printf("0000");
        return 0;
    }
    printf("1");
    long long pai1=0,pai2=0;
    pai1=(s1[0]-'0')*10+(s1[1]-'0');
    pai2=(s2[0]-'0')*10+(s2[1]-'0');
    if(pai1!=pai2){
        printf("000");
        return 0;
    }
    printf("1");
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
        if(!(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
            printf("00");
            return 0;
        }
        printf("1");
        if(abs(s1[2]-s2[2])!=1){
            printf("0");
            return 0;
        }
        printf("1");
        return 0;
    }
    if(s1[2]=='D'||s1[2]=='F'){
        if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
            printf("00");
            return 0;
        }
        printf("1");
        if(abs(s1[2]-s2[2])!=2){
            printf("0");
            return 0;
        }
        printf("1");
        return 0;
    }
    return 0;
}
